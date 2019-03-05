#ifndef EASY_LUA_H__
#define EASY_LUA_H__

#include <string>
#include <stdint.h>

#include "LuaOpt.h"

struct LuaFunc
{
	const char *name;
	lua_CFunction func;
};


#define CHECK_FUNCTION_EXIST(L, func_name) \
	m_error_code = LuaOpt::LuaPushStackVal(L, func_name); \
	if (m_error_code != 0) \
		return false 

class EasyLua
{
public:
	EasyLua();
	~EasyLua();

	bool Init();
	bool LoadFile(const std::string& filename);
	bool Reload();

	std::string GetErrorString();
	int32_t GetErrorCode(){ return m_error_code; }

	void RegisterFunctions(LuaFunc Funcs[], int n);
	void RegisterFunction(const char *name, lua_CFunction func);
private:
	bool DoLoadFile(const std::string& filename);

public:
	template<class T>
	bool GetGlobal(const std::string& var_name, T& val)
	{
		m_error_code = LuaOpt::GetGlobalVar<T>(m_lua, var_name, val);
		return m_error_code == 0;
	}

	template<class T>
	bool GetValue(T& val, int32_t pos)
	{
		m_error_code = LuaOpt::GetStackVal(m_lua, val, pos);
		return m_error_code == 0;
	}

	bool Call(std::string func_name, int32_t ret_num = 0)
	{
		CHECK_FUNCTION_EXIST(m_lua, func_name);
		m_error_code = lua_pcall(m_lua, 0, ret_num, 0);
		return m_error_code == 0;
	}

	template<typename ARG1>
	bool Call(std::string func_name, int32_t ret_num, const ARG1& arg1)
	{
		CHECK_FUNCTION_EXIST(m_lua, func_name);
		LuaOpt::CPushStackVal(m_lua, arg1);

		m_error_code = lua_pcall(m_lua, 1, ret_num, 0);
		return m_error_code == 0;
	}

	template<typename ARG1, typename ARG2>
	bool Call(std::string func_name, int32_t ret_num , const ARG1& arg1, const ARG2& arg2)
	{
		CHECK_FUNCTION_EXIST(m_lua, func_name);
		LuaOpt::CPushStackVal(m_lua, arg1);
		LuaOpt::CPushStackVal(m_lua, arg2);

		m_error_code = lua_pcall(m_lua, 2, ret_num, 0);
		return m_error_code == 0;
	}

	template<typename ARG1, typename ARG2, typename ARG3>
	bool Call(std::string func_name, int32_t ret_num, const ARG1& arg1, const ARG2& arg2, const ARG3& arg3)
	{
		CHECK_FUNCTION_EXIST(m_lua, func_name);
		LuaOpt::CPushStackVal(m_lua, arg1);
		LuaOpt::CPushStackVal(m_lua, arg2);
		LuaOpt::CPushStackVal(m_lua, arg3);

		m_error_code = lua_pcall(m_lua, 3, ret_num, 0);
		return m_error_code == 0;
	}

	template<typename ARG1, typename ARG2, typename ARG3, typename ARG4>
	bool Call(std::string func_name, int32_t ret_num, const ARG1& arg1, const ARG2& arg2, const ARG3& arg3, const ARG4& arg4)
	{
		CHECK_FUNCTION_EXIST(m_lua, func_name);
		LuaOpt::CPushStackVal(m_lua, arg1);
		LuaOpt::CPushStackVal(m_lua, arg2);
		LuaOpt::CPushStackVal(m_lua, arg3);
		LuaOpt::CPushStackVal(m_lua, arg4);

		m_error_code = lua_pcall(m_lua, 4, ret_num, 0);
		return m_error_code == 0;
	}

	template<typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5>
	bool Call(std::string func_name, int32_t ret_num, const ARG1& arg1, const ARG2& arg2, const ARG3& arg3, const ARG4& arg4, const ARG5& arg5)
	{
		CHECK_FUNCTION_EXIST(m_lua, func_name);
		LuaOpt::CPushStackVal(m_lua, arg1);
		LuaOpt::CPushStackVal(m_lua, arg2);
		LuaOpt::CPushStackVal(m_lua, arg3);
		LuaOpt::CPushStackVal(m_lua, arg4);
		LuaOpt::CPushStackVal(m_lua, arg5);

		m_error_code = lua_pcall(m_lua, 5, ret_num, 0);
		return m_error_code == 0;
	}

	template<typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6>
	bool Call(std::string func_name, int32_t ret_num, const ARG1& arg1, const ARG2& arg2, const ARG3& arg3, const ARG4& arg4, const ARG5& arg5, const ARG6& arg6)
	{
		CHECK_FUNCTION_EXIST(m_lua, func_name);
		LuaOpt::CPushStackVal(m_lua, arg1);
		LuaOpt::CPushStackVal(m_lua, arg2);
		LuaOpt::CPushStackVal(m_lua, arg3);
		LuaOpt::CPushStackVal(m_lua, arg4);
		LuaOpt::CPushStackVal(m_lua, arg5);
		LuaOpt::CPushStackVal(m_lua, arg6);

		m_error_code = lua_pcall(m_lua, 6, ret_num, 0);
		return m_error_code == 0;
	}

	template<typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7>
	bool Call(std::string func_name, int32_t ret_num, const ARG1& arg1, const ARG2& arg2, const ARG3& arg3, const ARG4& arg4, const ARG5& arg5, const ARG6& arg6, const ARG7& arg7)
	{
		CHECK_FUNCTION_EXIST(m_lua, func_name);
		LuaOpt::CPushStackVal(m_lua, arg1);
		LuaOpt::CPushStackVal(m_lua, arg2);
		LuaOpt::CPushStackVal(m_lua, arg3);
		LuaOpt::CPushStackVal(m_lua, arg4);
		LuaOpt::CPushStackVal(m_lua, arg5);
		LuaOpt::CPushStackVal(m_lua, arg6);
		LuaOpt::CPushStackVal(m_lua, arg7);

		m_error_code = lua_pcall(m_lua, 7, ret_num, 0);
		return m_error_code == 0;
	}

	template<typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7, typename ARG8>
	bool Call(std::string func_name, int32_t ret_num, const ARG1& arg1, const ARG2& arg2, const ARG3& arg3, const ARG4& arg4, const ARG5& arg5, const ARG6& arg6, const ARG7& arg7, const ARG8& arg8)
	{
		CHECK_FUNCTION_EXIST(m_lua, func_name);
		LuaOpt::CPushStackVal(m_lua, arg1);
		LuaOpt::CPushStackVal(m_lua, arg2);
		LuaOpt::CPushStackVal(m_lua, arg3);
		LuaOpt::CPushStackVal(m_lua, arg4);
		LuaOpt::CPushStackVal(m_lua, arg5);
		LuaOpt::CPushStackVal(m_lua, arg6);
		LuaOpt::CPushStackVal(m_lua, arg7);
		LuaOpt::CPushStackVal(m_lua, arg8);

		m_error_code = lua_pcall(m_lua, 8, ret_num, 0);
		return m_error_code == 0;
	}

	template<typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7, typename ARG8, typename ARG9>
	bool Call(std::string func_name, int32_t ret_num, const ARG1& arg1, const ARG2& arg2, const ARG3& arg3, const ARG4& arg4, const ARG5& arg5, const ARG6& arg6, const ARG7& arg7, const ARG8& arg8, const ARG9& arg9)
	{
		CHECK_FUNCTION_EXIST(m_lua, func_name);
		LuaOpt::CPushStackVal(m_lua, arg1);
		LuaOpt::CPushStackVal(m_lua, arg2);
		LuaOpt::CPushStackVal(m_lua, arg3);
		LuaOpt::CPushStackVal(m_lua, arg4);
		LuaOpt::CPushStackVal(m_lua, arg5);
		LuaOpt::CPushStackVal(m_lua, arg6);
		LuaOpt::CPushStackVal(m_lua, arg7);
		LuaOpt::CPushStackVal(m_lua, arg8);
		LuaOpt::CPushStackVal(m_lua, arg9);

		m_error_code = lua_pcall(m_lua, 9, ret_num, 0);
		return m_error_code == 0;
	}
private:
	lua_State* m_lua;
	std::string m_lua_filename;
	int32_t m_error_code;
};


#endif
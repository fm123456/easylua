#ifndef LUA_OPT_H__
#define LUA_OPT_H__


#include <string>
#include <stdint.h>

extern "C"
{
#include <lua/lua.h>
#include <lua/lauxlib.h> 
#include <lua/lualib.h>
}


#define GLOBAL_VAR_NOT_EXIST 10000
#define VAL_TYPE_NOT_MATCH   10001


class LuaOpt
{
public:
	template<class T>
	static int32_t GetGlobalVar(lua_State* L, const std::string& var_name, T& val)
	{
		int32_t ret = LuaPushStackVal(L, var_name);
		if (ret != 0)
			return ret;

		return GetStackVal(L, val);
	}

	static int32_t GetStackVal(lua_State* L, int8_t&  val, int32_t pos = -1);
	static int32_t GetStackVal(lua_State* L, int16_t& val, int32_t pos = -1);
	static int32_t GetStackVal(lua_State* L, int32_t& val, int32_t pos = -1);
	static int32_t GetStackVal(lua_State* L, int64_t& val, int32_t pos = -1);
	static int32_t GetStackVal(lua_State* L, float&   val, int32_t pos = -1);
	static int32_t GetStackVal(lua_State* L, double&  val, int32_t pos = -1);
	static int32_t GetStackVal(lua_State* L, std::string& val, int32_t pos = -1);
	static int32_t GetStackVal(lua_State* L, bool& val, int32_t pos = -1);

	static void CPushStackVal(lua_State* L, const int8_t&  val);
	static void CPushStackVal(lua_State* L, const int16_t& val);
	static void CPushStackVal(lua_State* L, const int32_t& val);
	static void CPushStackVal(lua_State* L, const int64_t& val);
	static void CPushStackVal(lua_State* L, const float&   val);
	static void CPushStackVal(lua_State* L, const double&  val);
	static void CPushStackVal(lua_State* L, const std::string& val);
	static void CPushStackVal(lua_State* L, const char* val);
	static void CPushStackVal(lua_State* L, const bool& val);

	static int32_t LuaPushStackVal(lua_State* L, const std::string& val);
private:
	template<class T>
	static int32_t GetInteger(lua_State* L, T&  val, int32_t pos = -1)
	{
		int32_t ret = lua_isinteger(L, pos);
		if (ret == 0)
		{
			char err_msg[256] = { 0 };
			_snprintf(err_msg, 256, "index %d is not integer", pos);
			lua_pushstring(L, err_msg);
			return VAL_TYPE_NOT_MATCH;
		}
		val = T(lua_tointeger(L, pos));
		return 0;
	}

	template<class T>
	static void CPushStackInteger(lua_State* L, const T&  val)
	{
		lua_pushinteger(L, val);
	}

	template<class T>
	static int32_t GetNumber(lua_State* L, T&  val, int32_t pos = -1)
	{
		int32_t ret = lua_isnumber(L, pos);
		if (ret == 0)
		{
			char err_msg[256] = { 0 };
			_snprintf(err_msg, 256, "index %d is not number", pos);
			lua_pushstring(L, err_msg);
			return VAL_TYPE_NOT_MATCH;
		}
		val = T(lua_tonumber(L, pos));
		return 0;
	}

	template<class T>
	static void CPushStackNumber(lua_State* L, const T&  val)
	{
		lua_pushnumber(L, val);
	}
};

#endif
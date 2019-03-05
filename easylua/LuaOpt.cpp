#include <stdio.h>
#include "LuaOpt.h"


int32_t LuaOpt::GetStackVal(lua_State* L,int8_t&  val, int32_t pos)
{
	return GetInteger<int8_t>(L, val, pos);
}

int32_t LuaOpt::GetStackVal(lua_State* L, int16_t& val, int32_t pos)
{
	return GetInteger<int16_t>(L, val, pos);
}

int32_t LuaOpt::GetStackVal(lua_State* L, int32_t& val, int32_t pos)
{
	return GetInteger<int32_t>(L, val, pos);
}

int32_t LuaOpt::GetStackVal(lua_State* L, int64_t& val, int32_t pos)
{
	return GetInteger<int64_t>(L, val, pos);
}

int32_t LuaOpt::GetStackVal(lua_State* L, float&   val, int32_t pos)
{
	return GetNumber<float>(L, val, pos);
}

int32_t LuaOpt::GetStackVal(lua_State* L,  double&  val, int32_t pos)
{
	return GetNumber<double>(L, val, pos);
}

int32_t LuaOpt::GetStackVal(lua_State* L, std::string& val, int32_t pos)
{
	int32_t ret = lua_isstring(L, pos);
	if (ret == 0)
	{
		char err_msg[256] = { 0 };
		_snprintf(err_msg, 256, "index %d is not string", pos);
		lua_pushstring(L, err_msg);
		return VAL_TYPE_NOT_MATCH;
	}
	val = lua_tostring(L, pos);
	return 0;
}

int32_t LuaOpt::GetStackVal(lua_State* L, bool& val, int32_t pos)
{
	int32_t ret = lua_isboolean(L, pos);
	if (ret == 0)
	{
		char err_msg[256] = { 0 };
		_snprintf(err_msg, 256, "index %d is not boolean", pos);
		lua_pushstring(L, err_msg);
		return VAL_TYPE_NOT_MATCH;
	}
	val = (lua_toboolean(L, pos) != 0);
	return 0;
}

void LuaOpt::CPushStackVal(lua_State* L, const int8_t&  val)
{
	CPushStackInteger<int8_t>(L, val);
}

void LuaOpt::CPushStackVal(lua_State* L, const int16_t& val)
{
	CPushStackInteger<int16_t>(L, val);
}

void LuaOpt::CPushStackVal(lua_State* L, const int32_t& val)
{
	CPushStackInteger<int32_t>(L, val);
}

void LuaOpt::CPushStackVal(lua_State* L, const int64_t& val)
{
	CPushStackInteger<int64_t>(L, val);
}

void LuaOpt::CPushStackVal(lua_State* L, const float&   val)
{
	CPushStackNumber<float>(L, val);
}

void LuaOpt::CPushStackVal(lua_State* L, const double&  val)
{
	CPushStackNumber<double>(L, val);
}

void LuaOpt::CPushStackVal(lua_State* L, const std::string& val)
{
	lua_pushstring(L, val.c_str());
}

void LuaOpt::CPushStackVal(lua_State* L, const char* val)
{
	lua_pushstring(L, val);
}

void LuaOpt::CPushStackVal(lua_State* L, const bool& val)
{
	lua_pushboolean(L, val);
}

int32_t LuaOpt::LuaPushStackVal(lua_State* L, const std::string& val)
{
	int32_t ret = lua_getglobal(L, val.c_str());
	if (ret == 0)
	{
		std::string err_msg = "global var not found :" + val;
		lua_pushstring(L, err_msg.c_str());
		return GLOBAL_VAR_NOT_EXIST;
	}

	return 0;
}


#include "EasyLua.h"


EasyLua::EasyLua() :m_lua(NULL), m_error_code(0)
{

}

EasyLua::~EasyLua()
{

}

bool EasyLua::Init()
{
	m_lua = luaL_newstate();
	if (!m_lua)
		return false;
	luaL_openlibs(m_lua);
	return true;
}

bool EasyLua::LoadFile(const std::string& filename)
{
	if (!DoLoadFile(filename))
		return false;

	m_lua_filename = filename;
	return true;
}

bool EasyLua::Reload()
{
	return DoLoadFile(m_lua_filename);
}

bool EasyLua::DoLoadFile(const std::string& filename)
{
	m_error_code = luaL_loadfile(m_lua, filename.c_str());
	if (m_error_code)
		return false;

	m_error_code = lua_pcall(m_lua, 0, 0, 0);
	if (m_error_code)
		return false;
	return true;
}

void EasyLua::RegisterFunctions(LuaFunc Funcs[], int n)
{
	if (!m_lua)  return;
	for (int i = 0; i < n; i++)
		lua_register(m_lua, Funcs[i].name, Funcs[i].func);
}

void EasyLua::RegisterFunction(const char *name, lua_CFunction func)
{
	if (!m_lua)  return;
	lua_register(m_lua, name, func);
}

std::string EasyLua::GetErrorString()
{
	if (lua_isstring(m_lua, -1))
		return std::string(lua_tostring(m_lua, -1));

	return "";
}
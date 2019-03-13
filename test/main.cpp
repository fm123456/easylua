#include <stdio.h>
#include <iostream>
#include "EasyLua.h"




template <typename ...Args>
inline void log_print(const char* fmt, const Args& ...args)
{
	printf(fmt, args...);
	printf("\n");
}


static int Add(lua_State *L)
{
	int val1, val2, val3;
	if (LuaOpt::GetStackVal(L, val1, 1) || LuaOpt::GetStackVal(L, val2, 2) || LuaOpt::GetStackVal(L, val3, 3))
	{
		return -1;
	}
	LuaOpt::CPushStackVal(L, val1+val2+val3);
	return 1;
}

static int PrintLua(lua_State* L)
{
	int val;
	if (LuaOpt::GetStackVal(L, val, 1))
	{
		return -1;
	}
	std::cout << val << std::endl;
	return 1;
}

int main()
{
	EasyLua easy_lua;
	if (!easy_lua.Init())
	{
		log_print("Init Filead");
		return -1;
	}
	if (!easy_lua.LoadFile("Hello.lua"))
	{
		log_print("loadfile error : %s", easy_lua.GetErrorString().c_str());
		return -1;
	}
	easy_lua.RegisterFunction("Add", Add);
	easy_lua.RegisterFunction("PrintLua", PrintLua);
	std::string str;
	if (!easy_lua.GetGlobal<std::string>("str", str))
	{
		log_print("GetGlobal error : %s", easy_lua.GetErrorString().c_str());
		return -1;
	}

	for (int i = 0; i < 5; i++)
	{
		if (!easy_lua.Call("increase", 1, i))
		{
			log_print("call increase function failed : %s", easy_lua.GetErrorString().c_str());
			return -1;
		}
		int32_t num;
		easy_lua.GetValue<int32_t>(num, -1);
		log_print("call increase function num : %d", num);
	}


	return 0;
	if (!easy_lua.Call("helloworld"))
	{
		log_print("Call error : %s", easy_lua.GetErrorString().c_str());
		return -1;
	}

	if (!easy_lua.Call("lua_print",0,"Nihao Lua"))
	{
		log_print("Call error : %s", easy_lua.GetErrorString().c_str());
		return -1;
	}
	easy_lua.Call("lua_print", 0, "Nihao Lua1");
	easy_lua.Call("lua_print", 0, "Nihao Lua3");
	easy_lua.Call("lua_print", 0, "Nihao Lua4");

	if (!easy_lua.Call("add", 1, 11, 1.1))
	{
		log_print("Call error : %s", easy_lua.GetErrorString().c_str());
		return -1;
	}
	float ret = 0;
	easy_lua.GetValue<float>(ret, -1);
	log_print("100 + 11 : %d", ret);


	return 0;
}
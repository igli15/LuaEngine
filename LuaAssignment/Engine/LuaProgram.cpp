//
// Created by Igli milaqi on 15/01/2019.
//

#include "LuaProgram.h"
#include <string>

int (*Engine::LuaProgram::function)(lua_State* l) = nullptr;

Engine::LuaProgram::LuaProgram(const std::string &filename)
{
    m_currentLuaState = GenerateProgram(filename);
    //Test<int,int>([](int i) { std::cout<<"WORKS: "<< i <<std::endl; return 1;},2);

    //if(function != nullptr)
   //    function(m_currentLuaState);
}

lua_State *Engine::LuaProgram::GenerateProgram(const std::string &filename)
{
    lua_State* luaState = luaL_newstate();
    luaL_openlibs(luaState);
    luaL_loadfile(luaState,filename.c_str());  // convert the filename string to C style string

    return luaState;
}

double Engine::LuaProgram::GetGlobalDouble(std::string varName)
{
    lua_getglobal(m_currentLuaState,varName.c_str());

    if(lua_isnumber(m_currentLuaState,-1))
    {
        double d = lua_tonumber(m_currentLuaState,-1);
        lua_pop(m_currentLuaState,1);
        return d;
    }
    else {
        std::cout<<"The global is not of type Double"<<std::endl;
        throw;
    }
}

int Engine::LuaProgram::GetGlobalBoolean(std::string varName)
{
    lua_getglobal(m_currentLuaState,varName.c_str());

    if(lua_isboolean(m_currentLuaState,-1))
    {
        double b = lua_toboolean(m_currentLuaState,-1);
        lua_pop(m_currentLuaState,1);
        return b;
    }
    else {
        std::cout<< "The global is not of type Boolean" <<std::endl;
        throw;
    }
}

int Engine::LuaProgram::GetGlobalInt(std::string varName)
{
    lua_getglobal(m_currentLuaState,varName.c_str());

    if(lua_isinteger(m_currentLuaState,-1))
    {
        int i = lua_tointeger(m_currentLuaState,-1);
        lua_pop(m_currentLuaState,1);
        return  i;
    }
    else {
        std::cout<<"The global is not of type Int"<<std::endl;
        throw;
    }
}

std::string Engine::LuaProgram::GetGlobalString(std::string varName)
{
    lua_getglobal(m_currentLuaState,varName.c_str());

    if(lua_isstring(m_currentLuaState,-1))
    {
        std::string s = lua_tostring(m_currentLuaState,-1);
        lua_pop(m_currentLuaState,1);
        return s;
    }
    else {
        std::cout<<"The global is not of type String"<<std::endl;
        throw;
    }
}


void Engine::LuaProgram::CallCurrentProgram()
{
    if(lua_pcall(m_currentLuaState,0,0,0) != 0)         //only if its zero it is called correctly
    {
        std::string error = lua_tostring(m_currentLuaState,-1);   //get the error from the top of the stack
        std::cout<<error<<std::endl;
        lua_pop(m_currentLuaState,1);
        throw error;
    }
}

void Engine::LuaProgram::SetGlobalDouble(std::string varName,double d)
{
    lua_pushnumber(m_currentLuaState,d);
    lua_setglobal(m_currentLuaState,varName.c_str());
}

void Engine::LuaProgram::SetGlobalInt(std::string varName, int i)
{
    lua_pushinteger(m_currentLuaState,i);
    lua_setglobal(m_currentLuaState,varName.c_str());
}

void Engine::LuaProgram::SetGlobalString(std::string varName, std::string s)
{
    lua_pushstring(m_currentLuaState,s.c_str());
    lua_setglobal(m_currentLuaState,varName.c_str());
}

void Engine::LuaProgram::SetGlobalBool(std::string varName,bool b)
{
    lua_pushboolean(m_currentLuaState,b);
    lua_setglobal(m_currentLuaState,varName.c_str());
}

void Engine::LuaProgram::GetGlobalFunction(std::string funcName, int NrOfArguments, int NrOfReturns)
{
    if(m_isFuncBeingCalled == true)
    {
        std::cout<<"You are already trying to get a function call that one first"<<std::endl;
        throw;
    }

    m_totalArgumentNumber = NrOfArguments;
    m_totalReturnNumber = NrOfReturns;
    m_isFuncBeingCalled = true;
    lua_getglobal(m_currentLuaState,funcName.c_str());
}

int Engine::LuaProgram::GetStackCount()
{
    return lua_gettop(m_currentLuaState);
}

void Engine::LuaProgram::CallGlobalFunction(std::string funcName)
{
    if(m_currentArgumentPassed > m_totalArgumentNumber)
    {
        std::cout<<"You have pushed more arguments then specified"<<std::endl;
        throw;
    }

    lua_call(m_currentLuaState,m_totalArgumentNumber,m_totalReturnNumber);
    m_isFuncBeingCalled = true;

}

void Engine::LuaProgram::CallFunctionInTable(std::string tableName, std::string fieldName)
{
    lua_getglobal(m_currentLuaState,tableName.c_str());
    lua_getfield(m_currentLuaState,-1,fieldName.c_str());
    lua_pcall(m_currentLuaState,0,0,0);
}



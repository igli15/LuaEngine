//
// Created by Igli milaqi on 15/01/2019.
//

#ifndef LUAASSIGNMENT_LUAPROGRAM_H
#define LUAASSIGNMENT_LUAPROGRAM_H

#include <iostream>
#include <lua.hpp>
#include <tuple>
#include <type_traits>

namespace Engine {

    class LuaProgram {

    public:
        LuaProgram(const std::string& filename);

        double GetGlobalDouble(std::string varName);
        int GetGlobalInt(std::string varName);
        std::string GetGlobalString(std::string varName);
        int GetGlobalBoolean(std::string varName);

        int GetStackCount();
        //All the set globals need to be set before the init call of the program.
        //All the global values in lua have to be not initialized otherwise it will
        //override our c++ value!!!
        void SetGlobalDouble(std::string varName,double d);
        void SetGlobalInt(std::string varName,int i);
        void SetGlobalString(std::string varName,std::string s);
        void SetGlobalBool(std::string varName,int b);

        //calls the lua file. used for initializing.
        void CallCurrentProgram();

        void GetGlobalFunction(std::string funcName,int NrOfArguments, int NrOfReturns);
        void CallGlobalFunction(std::string funcName);

        template <typename T>
        void PushFunctionArgument(T argument)
        {
            if(m_currentArgumentPassed >= m_totalArgumentNumber)
            {
                std::cout<<"You are passing more Arguments then specified"<<std::endl;
                throw;
            }

            if constexpr (std::is_same<T, int>())
            {
                m_currentArgumentPassed +=1;
                lua_pushinteger(m_currentLuaState, argument);
            }
            else if constexpr (std::is_same<T,std::string>())
            {
                m_currentArgumentPassed +=1;
                lua_pushstring(m_currentLuaState, argument.c_str());
            }
            else if constexpr (std::is_same<T,double>())
            {
                m_currentArgumentPassed +=1;
                lua_pushnumber(m_currentLuaState, argument);
            }
            else
            {
                std::cout<<"This type is not supported to be passed as an argument"<<std::endl;
                throw;
            }

        }

        template <typename T>
        T PopFunctionReturn()
        {
            if(m_isFuncBeingCalled == false)
            {
                std::cout<<"there is no function called to access return values from!"<<std::endl;
                throw;
            }
            if(m_currentReturnNumber == m_totalReturnNumber)
            {
                m_isFuncBeingCalled = false;
                m_currentReturnNumber = 0;
                m_currentArgumentPassed = 0;
                m_totalReturnNumber = 0;
                m_totalArgumentNumber = 0;
            }
            T returnType;

            if constexpr (std::is_same<T, int>())
            {
                m_currentReturnNumber +=1;
                returnType = lua_tointeger(m_currentLuaState,-1);
                lua_pop(m_currentLuaState,1);
                return  returnType;
            }
            else if constexpr (std::is_same<T, double>())
            {
                m_currentReturnNumber +=1;
                returnType = lua_tonumber(m_currentLuaState,-1);
                lua_pop(m_currentLuaState,1);
                return  returnType;
            }
            else if constexpr (std::is_same<T, std::string>())
            {
                m_currentReturnNumber +=1;
                returnType = lua_tostring(m_currentLuaState,-1);
                lua_pop(m_currentLuaState,1);
                return  returnType;
            } else
            {
                std::cout<<"This type is not supported to be passed as an argument"<<std::endl;
                throw;
            }

            return returnType;
        }

        template<typename T, typename U>
        void PushToTable(const std::string& tableName,T key,U value)
        {
            lua_getglobal(m_currentLuaState,tableName.c_str());

            if constexpr (std::is_same<T, int>())
            {
                lua_pushinteger(m_currentLuaState,key);
                if constexpr (std::is_same<U, int>())
                {
                    lua_pushinteger(m_currentLuaState,value);
                }
                else if constexpr (std::is_same<U, double>())
                {
                    lua_pushnumber(m_currentLuaState,value);
                }
                else if constexpr (std::is_same<U, std::string>())
                {
                    lua_pushstring(m_currentLuaState,value.c_str());
                }
                else if constexpr (std::is_same<U, bool>())
                {
                    lua_pushboolean(m_currentLuaState,value);
                }
            }
            else if constexpr (std::is_same<T, double>())
            {
                lua_pushnumber(m_currentLuaState,key);
                if constexpr (std::is_same<U, int>())
                {
                    lua_pushinteger(m_currentLuaState,value);
                }
                else if constexpr (std::is_same<U, double>())
                {
                    lua_pushnumber(m_currentLuaState,value);
                }
                else if constexpr (std::is_same<U, std::string>())
                {
                    lua_pushstring(m_currentLuaState,value.c_str());
                }
                else if constexpr (std::is_same<U, bool>())
                {
                    lua_pushboolean(m_currentLuaState,value);
                }
            }
            else if constexpr (std::is_same<T, std::string>())
            {
                lua_pushstring(m_currentLuaState,key.c_str());
                if constexpr (std::is_same<U, int>())
                {
                    lua_pushinteger(m_currentLuaState,value);
                }
                else if constexpr (std::is_same<U, double>())
                {
                    lua_pushnumber(m_currentLuaState,value);
                }
                else if constexpr (std::is_same<U, std::string>())
                {
                    lua_pushstring(m_currentLuaState,value.c_str());
                }
                else if constexpr (std::is_same<U, bool>())
                {
                    lua_pushboolean(m_currentLuaState,value);
                }
            }
            else if constexpr  (std::is_same<T,bool>())
            {
                lua_pushboolean(m_currentLuaState,key);
                if constexpr (std::is_same<U, int>())
                {
                    lua_pushinteger(m_currentLuaState,value);
                }
                else if constexpr (std::is_same<U, double>())
                {
                    lua_pushnumber(m_currentLuaState,value);
                }
                else if constexpr (std::is_same<U, std::string>())
                {
                    lua_pushstring(m_currentLuaState,value.c_str());
                }
                else if constexpr (std::is_same<U, bool>())
                {
                    lua_pushboolean(m_currentLuaState,value);
                }
            }
            else
            {
                std::cout<<"This type is not supported to be passed as an argument"<<std::endl;
                throw;
            }

            lua_settable(m_currentLuaState,-3);  // set all keys and values and pop them
            lua_pop(m_currentLuaState,1);   //pop the table
        }

    private:
       lua_State* GenerateProgram(const std::string &filename);
       lua_State* m_currentLuaState;

       int m_totalArgumentNumber = 0;
       int m_currentArgumentPassed = 0;
       int m_totalReturnNumber = 0;
       int m_currentReturnNumber = 0;
       bool m_isFuncBeingCalled = false;

    };
}


#endif //LUAASSIGNMENT_LUAPROGRAM_H

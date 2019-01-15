//
// Created by Igli milaqi on 15/01/2019.
//

#ifndef LUAASSIGNMENT_LUAPROGRAM_H
#define LUAASSIGNMENT_LUAPROGRAM_H

#include <iostream>
#include <lua.hpp>
#include <tuple>

namespace Engine {

    class LuaProgram {

    public:
        LuaProgram(const std::string& filename);

        double GetGlobalDouble(std::string varName);
        int GetGlobalInt(std::string varName);
        std::string GetGlobalString(std::string varName);

        void CallCurrentProgram();
        //void CallFunction(std::string funcName,);

    private:
       lua_State* GenerateProgram(const std::string &filename);
       lua_State* m_currentLuaState;


    };
}


#endif //LUAASSIGNMENT_LUAPROGRAM_H

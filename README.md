# LUA DOCUMENTATION

This project is a 2D C++ engine with Lua on top as a scripting language.The project provided uses a Hearthstone like PVE card game. There are 2 parts of Lua integration, the C++ Lua wrapper and the Lua code used to create the cards.


## C++ Wrapper

Lua is a [dynamic language](https://en.wikipedia.org/wiki/Dynamic_programming_language) while c++ is a [typed language](https://en.wikipedia.org/wiki/Strong_and_weak_typing). So in order to convert Lua to c++ and vice-versa we have to know and maintain the [Lua Stack](https://www.lua.org/pil/24.2.html). The provided c++ language provides a class called LuaProgram which is basically a wrapper to integrate Lua to c++. LuaProgram hides the stack form the users and maintains it by itself. It provides functionality to communicate with Lua as well as transferring c++ data to Lua scripts;

### Initializing A LuaProgram

Create a Lua program instance by providing the Lua file path.

`Engine::LuaProgram* luaProgram = new Engine::LuaProgram(path);`

Compile The Lua Program and the Lua script associated with it.

`luaProgram->CallCurrentProgram();`

### Geting Lua globals
You can get globals form Lua and set them to your liking. If you are setting globals you have to keep in mind to do it before Lua file is compiled/called.  

        int GetGlobalInt(std::string varName);

        std::string GetGlobalString(std::string varName);

        int GetGlobalBoolean(std::string varName);

        void SetGlobalDouble(std::string varName,double d);

        void SetGlobalInt(std::string varName,int i);

        void SetGlobalString(std::string varName,std::string s);

        void SetGlobalBool(std::string varName,bool b);`


### Calling Lua Functions in C++

First get the global function you want to call. You also have to provide the number of parameters and number of returns.

`void GetGlobalFunction(std::string funcName,int NrOfArguments, int NrOfReturns);`

Push the function arguments.(Depending on how many you requested)

` void PushFunctionArgument(T argument)`

Call The function

`void CallGlobalFunction(std::string funcName);`

Get the return values from stack.

`T PopFunctionReturn()`

### Pushing to a Lua table

Push a generic/templated value to the specified global table

`void PushToTable(const std::string& tableName,T key,U value)`

### Getting values from a Lua table

Get a generic/templated value from the specified global table

`U GetValueFromTable(const std::string& tableName, T key)`

### Call a function inside a Lua Table

`void CallFunctionInTable(std::string tableName, std::string fieldName)`

### Set a library to Lua

`void SetNewLibrary(const std::string& name,const struct luaL_Reg library[] )`

***

## Creating Cards in Lua

### Provided Callback

callbacks is a table filled with c++ function you can call from Lua. You can use them to make custom abilities.

`
callbacks  = {
    ["discardCard"] = nil;
    ["drawCard"] = nil;
    ["freezeOpponent"] = nil;
    ["decreaseCostOfACard"] = nil
}
`

### Creating the cards

every card must me created inside InitCards() function.

`function InitCards() end`

Calling cardTemplate.newCard with the specifies image path,name,description,cost,damage and an ability function.
For example:

`cardTemplate.newCard(path.."1.png" ,"Charlie","",4,2,ability)`

Note: you can also pass in an anonymous function instead of a predefined one like ability.




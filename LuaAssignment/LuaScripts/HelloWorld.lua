callbacks  = {

    ["discardCard"] = nil;
    ["drawCard"] = nil;
    ["freezeOpponent"] = nil;

}

function ability()

    callbacks["discardCard"]();

end



Card = {

    ["name"] = "test";
    ["filePath"] = "../LuaScripts/CardTest.lua";
    ["damage"] = 5;
    ["manaCost"] = 3;
    ["description"] = "Testing....";
    ["ability"] = ability;
}

callbacks  = {

    ["discardCard"] = nil;
    ["drawCard"] = nil;
    ["freezeOpponent"] = nil;

}

function ability()

    callbacks["discardCard"]();

end



card = {

    ["name"] = "test";
    ["filePath"] = "/Users/igli/Desktop/LuaEngine/LuaAssignment/Assets/CardArtTest.png";
    ["damage"] = 5;
    ["manaCost"] = 3;
    ["description"] = "Testing....";
    ["ability"] = ability;
}
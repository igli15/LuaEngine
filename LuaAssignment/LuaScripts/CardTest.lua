callbacks  = {

    ["discardCard"] = nil;
    ["drawCard"] = nil;
    ["freezeOpponent"] = nil;

    ["increaseDamageOfACard"] = nil;
    ["decreaseCostOfACard"] = nil
}

function ability()

    callbacks["decreaseCostOfACard"](1)

end

path = "/Users/igli/Desktop/LuaEngine/LuaAssignment/Assets/"

card = {

    ["name"] = "test";
    ["filePath"] = path .. "CardArtTest.png";
    ["damage"] = 5;
    ["manaCost"] = 3;
    ["description"] = "Testing....";
    ["ability"] = ability;
}
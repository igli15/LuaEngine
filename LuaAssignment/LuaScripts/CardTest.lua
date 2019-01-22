callbacks  = {

    ["discardCard"] = nil;
    ["drawCard"] = nil;
    ["freezeOpponent"] = nil;
    ["dealDamage"] = nil;
    ["increaseDamageOfACard"] = nil;
    ["decreaseCostOfACard"] = nil
}

function ability()

    callbacks["freezeOpponent"]()

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
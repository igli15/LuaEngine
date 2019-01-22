callbacks  = {

    ["discardCard"] = nil;
    ["drawCard"] = nil;
    ["freezeOpponent"] = nil;
    ["decreaseCostOfACard"] = nil
}

function ability()

    callbacks["decreaseCostOfACard"](1)

end

path = "/Users/igli/Desktop/LuaEngine/LuaAssignment/Assets/"

damage = 5;

description = "Heey";

card = {

    ["name"] = "test";
    ["filePath"] = path .. "CardArtTest.png";
    ["damage"] = damage;
    ["manaCost"] = 3;
    ["description"] = (damage > 0 and "Deal " .. damage .. " Damage" or "") .."\n" ..description;
    ["ability"] = ability;
}


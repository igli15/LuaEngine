callbacks  = {

    ["discardCard"] = nil;
    ["drawCard"] = nil;
    ["freezeOpponent"] = nil;
    ["decreaseCostOfACard"] = nil
}

function ability()

   callbacks["freezeOpponent"]();
    print("LUA ABILITY CALLED")
end

path = "/Users/igli/Desktop/LuaEngine/LuaAssignment/Assets/"

damage = 5

description = "Heey"

function InitCards()


    cardTemplate.newCard(path.."CardArtTest.png" ,"Test",description,3,damage,ability)
    cardTemplate.newCard(path.."CardArtTest.png" ,"Test",description,3,damage,ability)
    cardTemplate.newCard(path.."CardArtTest.png" ,"Test",description,3,damage,ability)
    cardTemplate.newCard(path.."CardArtTest.png" ,"Test",description,3,damage,ability)
    cardTemplate.newCard(path.."CardArtTest.png" ,"Test",description,3,damage,ability)

end


card = {

    ["name"] = "test";
    ["filePath"] = path .. "CardArtTest.png";
    ["damage"] = damage;
    ["manaCost"] = 3;
    ["description"] = (damage > 0 and "Deal " .. damage .. " Damage" or "") .."\n" .. description;
    ["ability"] = ability;
}


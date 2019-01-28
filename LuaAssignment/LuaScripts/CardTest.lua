callbacks  = {

    ["discardCard"] = nil;
    ["drawCard"] = nil;
    ["freezeOpponent"] = nil;
    ["decreaseCostOfACard"] = nil
}

function ability ()

end
path = "/Users/igli/Desktop/LuaEngine/LuaAssignment/Assets/"

damage = 30

description = "Heey"

description = (damage > 0 and "Deal " .. damage .. " Damage" or "") .. "\n" .. description;

function InitCards()


    cardTemplate.newCard(path.."2.png" ,"Grubbytia",description,2,damage,ability)
    cardTemplate.newCard(path.."3.png" ,"Drogtia",description,4,damage,ability)
    cardTemplate.newCard(path.."4.png" ,"Malereed",description,4,damage,ability)
    cardTemplate.newCard(path.."5.png" ,"Tiastomper",description,4,damage,ability)
    cardTemplate.newCard(path.."6.png" ,"Tiaconda",description,4,damage,ability)
    cardTemplate.newCard(path.."7.png" ,"Dracoreed",description,4,damage,ability)
    cardTemplate.newCard(path.."8.png" ,"Reecrusher",description,4,damage,ability)
    cardTemplate.newCard(path.."9.png" ,"Seratia",description,4,damage,ability)
    cardTemplate.newCard(path.."10.png" ,"Capritia",description,4,damage,ability)
    cardTemplate.newCard(path.."11.png" ,"Wickedtia",description,4,damage,ability)
    cardTemplate.newCard(path.."12.png" ,"Maletia",description,4,damage,ability)
    cardTemplate.newCard(path.."13.png" ,"Wendtia",description,4,damage,ability)
    cardTemplate.newCard(path.."14.png" ,"Grindyreed",description,4,damage,ability)
    cardTemplate.newCard(path.."15.png" ,"Reederion",description,4,damage,ability)
    cardTemplate.newCard(path.."16.png" ,"Yoreed",description,4,damage,ability)
    cardTemplate.newCard(path.."17.png" ,"Viserreed",description,4,damage,ability)
    cardTemplate.newCard(path.."18.png" ,"Hydratia",description,4,damage,ability)
    cardTemplate.newCard(path.."19.png" ,"Suzan","Deal 8 Damage \nFreeze Enemy",8,8,function() callbacks["freezeOpponent"](); end )
    cardTemplate.newCard(path.."20.png" ,"Horsereed",description,4,damage,ability)

end
callbacks  = {

    ["discardCard"] = nil;
    ["drawCard"] = nil;
    ["freezeOpponent"] = nil;
    ["decreaseCostOfACard"] = nil
}

function ability ()

end

path = "/Users/igli/Desktop/LuaEngine/LuaAssignment/Assets/"

function InitCards()

    cardTemplate.newCard(path.."1.png" ,"Charlie","Deal 3 Damage\nDrawACard",6,3,function() callbacks["drawCard"](); end)
    cardTemplate.newCard(path.."2.png" ,"Grubbytia","Deal 2 Damage",2,2,ability)
    cardTemplate.newCard(path.."3.png" ,"Drogtia","Deal 6 Damage",7,6,ability)
    cardTemplate.newCard(path.."4.png" ,"Malereed","Deal 2 Damage \n FreezeEnemy",4,2,function() callbacks["freezeOpponent"](); end)
    cardTemplate.newCard(path.."5.png" ,"Tiastomper","Decrease cost of \na random card \nby 1",3,0,function() callbacks["decreaseCostOfACard"](1); end)
    cardTemplate.newCard(path.."6.png" ,"Tiaconda","Decrease cost of \na random card by \nby 3",5,0,function() callbacks["decreaseCostOfACard"](3); end)
    cardTemplate.newCard(path.."7.png" ,"Dracoreed","Deal 2 Damage\nFreeze Enemy \nDraw A Card",5,2,function()callbacks ["freezeOpponent"](); callbacks["drawCard"](); end)
    cardTemplate.newCard(path.."8.png" ,"Reecrusher","Deal 10 Damage\nDiscard 2 Cards",10,10,function()callbacks ["discardCard"](); callbacks["discardCard"](); end)
    cardTemplate.newCard(path.."9.png" ,"Seratia","Draw 2 Cards",6,0,function() callbacks["drawCard"](); end)
    cardTemplate.newCard(path.."10.png" ,"Capritia","Deal 3 Damage\nDrawACard",6,3,function() callbacks["drawCard"](); end)
    cardTemplate.newCard(path.."11.png" ,"Wickedtia","Deal 3 Damage",3,3,ability)
    cardTemplate.newCard(path.."12.png" ,"Maletia","Deal 6 Damage",8,6,ability)
    cardTemplate.newCard(path.."13.png" ,"Wendtia","Deal 1 Damage\nFreeze Enemy",1,1,function() callbacks["freezeOpponent"](); end)
    cardTemplate.newCard(path.."14.png" ,"Grindyreed","Deal 5 Damage",4,5,ability)
    cardTemplate.newCard(path.."15.png" ,"Reederion","Deal 3 Damage\nDiscard one card",1,3,function()callbacks ["discardCard"](); end)
    cardTemplate.newCard(path.."16.png" ,"Yoreed","Deal 2 Damage \n FreezeEnemy",4,2,function() callbacks["freezeOpponent"](); end)
    cardTemplate.newCard(path.."17.png" ,"Viserreed","Deal 3 Damage",2,3,ability)
    cardTemplate.newCard(path.."18.png" ,"Hydratia","Deal 6 Damage",7,6,ability)
    cardTemplate.newCard(path.."19.png" ,"Suzan","Deal 8 Damage \nFreeze Enemy",8,8,function() callbacks["freezeOpponent"](); end )
    cardTemplate.newCard(path.."20.png" ,"Horsereed","Deal 30 Damage",11,30,ability)

end
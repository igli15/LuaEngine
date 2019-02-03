Enemy = {}

function Enemy:new(imagePath,health)

    local newEnemy= {}
    setmetatable(newEnemy,self);
    self.__index = self;
    newEnemy.imagePath = imagePath;
    newEnemy.health = health;
    return newEnemy
end

path = "/Users/igli/Desktop/LuaEngine/LuaAssignment/Assets/"

enemy = Enemy:new(path.."EnemyArt",30)

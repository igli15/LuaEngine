print("HELLO FROM LUA")

test = {
    [1] = 3;
}


function sum(a,b)

return a+b

end

function concat(a,b)

return a..b

end

function p()
    print(test[1]);

end
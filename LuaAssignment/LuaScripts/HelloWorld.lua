print("HELLO FROM LUA")

test = {
    ["t"] = 3;
}


function sum(a,b)

return a+b

end

function concat(a,b)

return a..b

end

function p()
    print(test["t"]);

end
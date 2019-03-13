str = "I am so cool"
tb1 = {name="shun", id=20181202}

num = 1

function add( a , b )
	-- body
	return a + b,a
end

function get_string( ... )
	-- body
	return "Hello World"
end

function to_lower( str )
	-- body
	return string.lower(str)
end

function min(a, b)
	-- body
	return math.min(a,b)
end

function max(a, b)
	-- body
	return math.max(a,b)
end

function increase(i)
	num = Add(i,i+1,i+2)
	PrintLua(num)
	return num
end

a=gets.split /[A-Z]/
p a[1,a.size-2].sum{|x|3-x.size%4}

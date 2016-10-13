input N
for i = 1:N
     input rect[i].h
     input rect[i].w
let cost[0] = 0
for i =2:N
     let cost[i] = INF
     for j =1:i-1
         cost[i] = min(cost[i],cost[j]+rect[i].h*rect[j+1].w)
print cost[N]
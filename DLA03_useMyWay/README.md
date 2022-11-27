# idea DLA03_useMyWay
## function
### vetor createSeed()
this function to create random start point in the image, everytime call this function, create one point, return the position(x,y)(store in a vector) of this point.

### vector randomPoint(centrePoint)
this function focus on one centre point, random grab point surrounding by this point. everytime call this function, grab one point, return the position(x,y)(store in a vector) of the point.

### bool changePointColour(point)
this function focus on one point grabed in function "randomPoint()". then check edge (width,height) & ifHitted. If within the edge and not hitted, give it a colour, return ture. 

### array[] walk (point)
this function put all of the random surrounding point in to an array and return the pointer

### main()
![](./Screenshot%20from%202022-11-27%2012-16-20.png)
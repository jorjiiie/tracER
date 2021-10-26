# tracER
ray tracer in c++


Implements Sphere, Triangle, and Rectangle geometry

Custom BVH works but it's pretty bad, and only works well when geometry isn't clustered together (hits are less common then misses). Typically is more efficient when object count > 1000 or so

Has diffuse and and glossy shaders

Can't import files unless you hardcode the format - SceneIO.cpp can only do edited .ply to scene conversion

very messy and I apologize for things that don't make sense. Maybe I'll find the time to refactor the code into something more readable and consistent

# Example Scenes:

Cornell Box

![Alt text](https://cdn.discordapp.com/attachments/811362399194054667/902704196342661201/uwuuwuuwu.png)

Imported Stanford Bunny
![Alt text](https://cdn.discordapp.com/attachments/811362399194054667/902704735906304060/joe.jpg)

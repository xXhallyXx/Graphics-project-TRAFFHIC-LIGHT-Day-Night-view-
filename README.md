# Graphics-project-TRAFFHIC-LIGHT-Day-Night-view-

Project Title :   City Traffic Scene with Day–Night Mode using OpenGL (GLUT)
Introduction :
This project is a 2D City Traffic Scene with Day–Night Mode. It can flip between day and night ,all with OpenGL and GLUT. This is a tiny version of a real city, the usual stuffs are roads, buildings, trees, cars, traffic lights, and zebra crossing . It has clouds, the sun, moon, and stars. This project illustrates some key computer graphics concepts. It is all about getting how 2D coordinate systems work, making digital stuff, and then getting it to move when nothing else is happening. Here also look at making traffic lights work with timers and take actions by pressing keys or clicking mouse. Cars stop and go with the traffic lights, clouds float by in the daytime, and can change moving speed . When it gets dark, stars pop out and glide across the night sky. This project really gives a good handle on how animation and interaction really happen with OpenGL.
Project Graph – 
The project uses an orthographic 2D projection defined by:
•	X-axis range: 0 to 900
•	Y-axis range: 0 to 500
The road and zebra crossing at the bottom of the screen. The buildings and trees are situated right above the road, and the sky fills up the top part. Objects move because their positions are continuously updated. Random star locations are generated to create a realistic night sky.
List of objects assigning an object ID –
SL#	Object ID	Object Name
1	OBJ_01	Circle
2	OBJ_02	Sun/Moon
3	OBJ_03	Cloud
4	OBJ_04	Star
5	OBJ_05	Road
6	OBJ_06	Zebra Crossing
7	OBJ_07	Grass
8	OBJ_08	Building
9	OBJ_09	Window
10	OBJ_10	Tree
11	OBJ_11	Traffic Light
12	OBJ_12	Car

1.	List of Functions To Represent Objects- 
SL#	Object_ID 	Function Name
1	OBJ_01	circle()
2	OBJ_02	sun_or_moon()
3	OBJ_03	cloud()
4	OBJ_04	stars()
5	OBJ_05	road()
6	OBJ_06	zebraCrossing()
7	OBJ_07	grass()
8	OBJ_08	buildings()
9	OBJ_09	window()
10	OBJ_10	tree()
11	OBJ_11	tafficLight()
12	OBJ_12	car()

2.	List of Animation Functions with ID – 
SL#	Animation Function	Animation Function ID
1	animate()	ANIM_01
2	timer()	ANIM_02
3	keyboard()	ANIM_03
4	display()	ANIM_04
5	mouse()	ANIM_05

Working Process :
The City Traffic Scene project was developed step by step using OpenGL and GLUT. Here a 2D orthographic coordinate system was set for all objects could be placed properly on the screen. Shapes were created using OpenGL primitives. A common circle function was draw objects, such as the sun, moon, clouds, stars, traffic lights and car wheels. Then, static objects such as roads, zebra crossings, buildings, trees, grass and windows were designed and positioned to form a city view. Animation continuously updating object positions, such as car movement depends on the traffic light controlled by a timer function and cars move slower speed during night mode compared to day mode. Day and night modes were using a control variable that changes the sky color, sun or moon, cloud invisible, grass color, and star movement. User interaction was added keyboard and mouse inputs to switch modes and control animation speed. The main challenges faced were proper object positioning, synchronizing car movement with traffic lights, maintaining animation, and handling multiple changes during day-night mood which were solved carefully designing and testing.


Initial Project Description :
The proposed project is a 2D City Traffic Scene with Day–Night Mode developed using OpenGL (GLUT). The project simulates a real-life city environment including roads, cars, buildings, trees, traffic signals, zebra crossing, clouds, sun, moon, and stars. The system demonstrates animation, timer-based traffic control, and keyboard interaction for switching between day and night modes.

Scene-1 
Objects: Sky, Sun, Buildings, Trees, Road, Grass
Animations: (i) No vehicle movement (ii) Static environment
Mouse Interaction: No mouse interaction
Keyboard Interaction: No keyboard interaction
Scene-2 
Objects: Cars, Road, Traffic Light, Zebra Crossing, Buildings, Trees, Clouds
Animations: (i)  Cars move when traffic signal is green (ii) Clouds move continuously across the sky
Mouse Interaction: No mouse interaction
Keyboard Interaction: No keyboard interaction
Scene-3 
Objects: Traffic Light, Cars, Road, Zebra Crossing
Animations: (i) Traffic signal changes automatically using timer (Red → Yellow → Green) (ii) Car movement depends on signal state
Mouse Interaction: No mouse interaction
Keyboard Interaction: No keyboard interaction
Scene-4 
Objects: Moon, Stars, Buildings, Trees, Road, Cars, Traffic Light, Zebra Crossing
Animations: (i) Cars move based on traffic signal (ii) Stars displayed randomly in night sky
Mouse Interaction: No mouse interaction
Keyboard Interaction: Press 'N' or 'n' to toggle between Day and Night mode
 
Scene to Scene Transition: Scene transitions occur logically within the same program flow. Day and night scenes are switched dynamically using keyboard input. Traffic behavior and animations remain consistent across all scenes, resulting in a complete and realistic city traffic simulation.

Conclusion : 
The City Traffic Scene project shows how OpenGL can be used for 2D graphics and animation, especially with its day-night changes and interactive. Here adding things like traffic lights, moving clouds and stars, zebra crossings, and able to use keyboard and mouse makes the simulation feel more real. Here got a good grasp of how OpenGL primitives work from this project. Also figured out transformations, animation logic, timer functions, and how to handle user interaction. This project met all the course requirements and provides a good foundation for learning more advanced computer graphics.






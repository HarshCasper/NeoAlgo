#Snake Game
import turtle
import time
import random

score = 0
highscore = 0
delay = 0.2

#Set up the screen
window = turtle.Screen()
window.title("Snake Game")
window.bgcolor("black")
window.setup(height=600,width=600)
window.tracer(0)

#Create the snake's head
head = turtle.Turtle()
head.speed(0)
head.shape("square")
head.color("white")
head.penup()
head.goto(0,100)
head.direction = "stop"

#Create snake food
food = turtle.Turtle()
food.speed(0)
food.shape("circle")
food.color("red")
food.penup()
food.shapesize(0.50,0.50)
food.goto(0,0)

segments = []

#Display the score
board = turtle.Turtle()
board.speed(0)
board.shape("square")
board.color("white")
board.penup()
board.hideturtle()
board.goto(0, 260)
board.write("Score: 0  High Score: {}".format(highscore), align="center", font=("Courier",24,"normal"))


#Directions for movement
def move():
    if head.direction == "up":
        y = head.ycor()
        head.sety(y+20)
    if head.direction == "down":
        y = head.ycor()
        head.sety(y-20)
    if head.direction == "right":
        x = head.xcor()
        head.setx(x + 20)
    if head.direction == "left":
        x = head.xcor()
        head.setx(x - 20)

#Setting the directions
def go_down():
    if head.direction!="up":
        head.direction = "down"
def go_up():
    if head.direction!="down":
        head.direction = "up"
def go_right():
    if head.direction!="left":
        head.direction = "right"
def go_left():
    if head.direction!="right":
        head.direction = "left"

#Keyboard Bindings
window.listen()
window.onkey(go_up, "w")
window.onkey(go_down, "s")
window.onkey(go_left, "a")
window.onkey(go_right, "d")

#Main game loop
while True:
    window.update()

    time.sleep(delay)
    # Moving food to random position
    if head.distance(food) < 15:
        x = random.randint(-290, 290)
        y = random.randint(-290, 290)
        food.goto(x, y)

        # Create new segments
        new_seg = turtle.Turtle()
        new_seg.speed(0)
        new_seg.shape("square")
        new_seg.color("white")
        new_seg.penup()
        segments.append(new_seg)

        #Increse the score
        score = score + 10
        if(score > highscore):
            highscore = score

        #Update the score
        board.clear()
        board.write("Score: {}  High Score: {}".format(score, highscore), align="center", font=("Courier", 24, "normal"))

    # Moving the segment
    for index in range(len(segments) - 1, 0, -1):
        x = segments[index - 1].xcor()
        y = segments[index - 1].ycor()
        segments[index].goto(x, y)

    # Move segment 0 to where head is
    if len(segments) > 0:
        x = head.xcor()
        y = head.ycor()
        segments[0].goto(x, y)

    move()

    # Check for border collision
    if head.xcor() > 290 or head.xcor() < -290 or head.ycor() > 290 or head.ycor() < -290 :
        time.sleep(1)
        head.goto(0, 0)
        head.direction = "stop"

        # Hide the segments
        for segment in segments :
            segment.goto(1000, 1000)
        # Clear the segments
        segments = []

        #Reset score
        score = 0
        # Update the score
        board.clear()
        board.write("Score: {}  High Score: {}".format(score, highscore), align="center", font=("Courier", 24, "normal"))


    # Check for body collisions
    for segment in segments :
        if segment.distance(head) < 20 :
            time.sleep(1)
            head.goto(0, 0)
            head.direction = "stop"

            # Hide the segments
            for segment in segments:
                segment.goto(1000, 1000)
            # Clear the segments
            segments.clear()

            # Reset score
            score = 0
            # Update the score
            board.clear()
            board.write("Score: {}  High Score: {}".format(score, highscore), align="center", font=("Courier", 24, "normal"))

















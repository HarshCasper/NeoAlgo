"""
A fun and interactive snake game using GUI programming in python
It is very user friendly and contains appropriate comments
It covers all the corner test cases also
"""
# Import the necessary libraries
import turtle
import time
import random

# Initialize the scores
score = 0
highscore = 0
delay = 0.2

# Set up the screen
window = turtle.Screen()
window.title("Snake Game")
window.bgcolor("black")
window.setup(height=600, width=600)
window.tracer(0)

# Create the snake's head
head = turtle.Turtle()
head.speed(0)
head.shape("square")
head.color("white")
head.penup()
head.goto(0, 100)
head.direction = "stop"

# Create snake food
food = turtle.Turtle()
food.speed(0)
food.shape("circle")
food.color("red")
food.penup()
food.shapesize(0.50, 0.50)
food.goto(0, 0)

segments = []

# Display the score
board = turtle.Turtle()
board.speed(0)
board.shape("square")
board.color("white")
board.penup()
board.hideturtle()
board.goto(0, 260)
board.write("Score: 0  High Score: {}".format(highscore))


# Directions for movement
def move():
    if head.direction == "up":
        y1 = head.ycor()
        head.sety(y1+20)
    if head.direction == "down":
        y1 = head.ycor()
        head.sety(y1-20)
    if head.direction == "right":
        x1 = head.xcor()
        head.setx(x1 + 20)
    if head.direction == "left":
        x1 = head.xcor()
        head.setx(x1 - 20)


# Setting the directions
def go_down():
    if head.direction != "up":
        head.direction = "down"


def go_up():
    if head.direction != "down":
        head.direction = "up"


def go_right():
    if head.direction != "left":
        head.direction = "right"


def go_left():
    if head.direction != "right":
        head.direction = "left"


# Keyboard Bindings
window.listen()
window.onkey(go_up, "w")
window.onkey(go_down, "s")
window.onkey(go_left, "a")
window.onkey(go_right, "d")

# Main game loop
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

        # Increse the score
        score = score + 10
        if score > highscore :
            highscore = score

        # Update the score
        board.clear()
        board.write("Score: {}  High Score: {}".format(score, highscore))

    # Moving the segment
    for index in range(len(segments) - 1, 0, -1):
        x = int(segments[index - 1].xcor())
        y = int(segments[index - 1].ycor())
        segments[index].goto(x, y)

    # Move segment 0 to where head is
    if len(segments) > 0:
        x = int(head.xcor())
        y = int(head.ycor())
        segments[0].goto(x, y)

    move()

    # Check for border collision
    z1 = head.xcor()
    z2 = head.ycor()
    if z1 > 290 or z1 < -290 or z2 > 290 or z2 < -290 :
        time.sleep(1)
        head.goto(0, 0)
        head.direction = "stop"

        # Hide the segments
        for segment in segments :
            segment.goto(1000, 1000)
        # Clear the segments
        segments = []

        # Reset score
        score = 0
        # Update the score
        board.clear()
        board.write("Score: {}  High Score: {}".format(score, highscore))

    # Check for body collisions
    for segment in segments :
        if segment.distance(head) < 20 :
            time.sleep(1)
            head.goto(0, 0)
            head.direction = "stop"

            # Hide the segments
            for seg in segments:
                seg.goto(1000, 1000)
            # Clear the segments
            segments.clear()

            # Reset score
            score = 0
            # Update the score
            board.clear()
            board.write("Score: {}  High Score: {}".format(score, highscore))

import turtle

# Set up the screen
screen = turtle.Screen()
screen.bgcolor("white")

# Create a turtle object
my_turtle = turtle.Turtle()
my_turtle.speed(1)

# Draw the letters of the name "AKHIL"
my_turtle.penup()
my_turtle.goto(-100, 0)
my_turtle.pendown()

# Draw the letter "A"
my_turtle.right(30)
my_turtle.forward(100)
my_turtle.right(120)
my_turtle.forward(100)
my_turtle.right(120)
my_turtle.forward(100)
my_turtle.right(30)

# Move the turtle to the right position for the next letter
my_turtle.penup()
my_turtle.forward(50)
my_turtle.pendown()

# Draw the letter "K"
my_turtle.right(30)
my_turtle.forward(50)
my_turtle.right(120)
my_turtle.forward(50)
my_turtle.right(120)
my_turtle.forward(50)
my_turtle.right(30)

# Move the turtle to the right position for the next letter
my_turtle.penup()
my_turtle.forward(50)
my_turtle.pendown()

# Draw the letter "H"
my_turtle.right(30)
my_turtle.forward(50)
my_turtle.right(120)
my_turtle.forward(50)
my_turtle.right(120)
my_turtle.forward(50)
my_turtle.right(30)

# Move the turtle to the right position for the next letter
my_turtle.penup()
my_turtle.forward(50)
my_turtle.pendown()

# Draw the letter "I"
my_turtle.right(30)
my_turtle.forward(50)
my_turtle.right(120)
my_turtle.forward(50)
my_turtle.right(120)
my_turtle.forward(50)
my_turtle.right(30)

# Move the turtle to the right position for the next letter
my_turtle.penup()
my_turtle.forward(50)
my_turtle.pendown()

# Draw the letter "L"
my_turtle.right(30)
my_turtle.forward(50)
my_turtle.right(120)
my_turtle.forward(50)
my_turtle.right(120)
my_turtle.forward(50)
my_turtle.right(30)

# Hide the turtle and close the window
my_turtle.hideturtle()
turtle.done()
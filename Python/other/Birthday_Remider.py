from datetime import datetime
import time
 
def get_birthday():
 date_str = input("Enter your birth date in DD/MM/YYYY: ")
 try:
   birthday = datetime.strptime(date_str, "%d/%m/%Y")
 except TypeError:
   birthday = datetime.datetime(*(time.strptime(date_str, "%d/%m/%Y")[0:6]))
 return birthday
 
def howManyDaysRemaining(birth_date):
  now = datetime.now()
  cy = datetime(now.year, birth_date.month, birth_date.day) #cy=current year
  days = (cy - now).days
  if days < 0:
    ny = datetime(now.year+1, birth_date.month, birth_date.day) #ny = next year 
    days = (ny - now).days
  return days
 
birthday = get_birthday()
nb = howManyDaysRemaining(birthday) 
print("Your birthday is coming in: ", nb, " days")

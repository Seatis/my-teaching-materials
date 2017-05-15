# Create a Heroku database

- Visit your [Heroku dashboard](https://dashboard.heroku.com/apps)
- Log in (if you haven't done yet)
  Here you can see a list of your apps
- Pick your app
- Under `Resources` search for `postgre` and add it (it is free)
- Your app should be `Hobby dev - free`
- Open your template project from the previous exercise with IntelliJ
- Add `runtime('org.postgresql:postgresql')` to your dependencies
- From now you can check the username, password and url for your database under `Database Credentials`
- Set the correct data in your properies file to connect: username, password, etc
  like:
`spring.datasource.url=jdbc:postgresql://ec2-54-247-119-245.eu-west-1.compute.amazonaws.com:5432/da0ifqee69o5v6?sslmode=require
spring.datasource.username =dxacfgggnugjcm
spring.datasource.password = 7fc3449af8815e6f6fe201829e3d0b3cff606ad01946850b4467029a8bacb669
spring.jpa.hibernate.ddl-auto=create-drop`

# Publish your work

- Modify your Reddit and FoxClub projects to use postgres and deploy them to heroku

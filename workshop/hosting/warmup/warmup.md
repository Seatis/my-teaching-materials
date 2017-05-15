# First Heroku Project
## Check the previously installed Heroku CLI
 - Open a cmd/terminal (Heroku is incompatible with git bash/Cygwin/MinGW)
 - `heroku login`
 - Log in using the email address and password you used when creating your Heroku account
 - You should get `Logged in as example@mail.com`

 ## Initialize the project
 - `git clone https://github.com/greenfox-academy/heroku-project.git`
 - `cd heroku-project`
 - `heroku create`
 - You should get `Creating app... done` and some weird project name
 - `git push heroku master`
 - `heroku open`
 - You should get a freshly opened new web browser tab, containing your online server's frontend
 - `heroku logs` show you the application logs
 - Also try `heroku logs --tail`. It is continuously waiting for new lines, and display them as they appear 
 - Open [Heroku Dashboard](https://dashboard.heroku.com/apps). You can manage your projects here. You can also check the logs, application status here.

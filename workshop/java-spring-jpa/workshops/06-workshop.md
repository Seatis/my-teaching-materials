# Workshop06 Add updating function

- Work on the same project
- Add new column to your view table with "edit" text
- Make it possible to click on it
- Extend the controller class with `edit()` method mapping to `/{id}/edit`
- The aim is to edit the clicked item on a redirected editing page
- The edit page should be a simple form
- The user should be able to edit the name of the todo item, and the status of urgent and done
- Again we will need a uniq @PathVariable, which in our case is the `long id` of the todo item
- Use the `delete(id)` method of the repository passing the id in it
- Don't forget to specify the id in the template when you create the 'delete' link
- After the user deleted the item we should be redirected to the list page

<img src="../assets/EditTodos.PNG">

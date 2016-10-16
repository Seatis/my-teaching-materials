# Styleguide for HTML & CSS

We follow the styleguide of Google: https://google.github.io/styleguide/htmlcssguide.xml

## Exceptions
 - HTML
   - Optional Tags
 - CSS
   - Declaration Order

## Additions
 - HTML
   - Self closing slashes `/` for `void` HTML tags are optional in HTML5, be consistent, either use it in every `void` tag or in none
     - we will democratically agree to use it nowhere
       - list of `void` tags in HTML5: https://www.w3.org/TR/html-markup/syntax.html#syntax-elements
         ```html
         <!-- Good -->
         <link name="value">
         <img src="value">

         <!-- Bad -->
         <link name="value"></link>
         <img src="value"/>
         ```
 - CSS
   - Use `::` instead of `:` on pseudo element selectors. Eg.:
     ```css
     /* Good */
     .my-class::after {
       content: "apple";
     }

     /* Bad */
     .my-class:after {
       content: "apple";
     }
     ```


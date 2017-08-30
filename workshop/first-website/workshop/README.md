# Workshop
*A simple guide for facilitating*

## Goals
The main goal of the workshop to show them how easy is to create something.
It's alright to have this workshop a bit more frontal and use the projector all
the time.

## Steps
 -  **Keep things tidy.**
    Create a folder for all your Green Fox materials. Then within that, a folder for the first week, and within that a folder for the first day's assignment.
    Check the recomended [folder structure](https://github.com/greenfox-academy/definitions/blob/master/github-usage.md#folder-structure) and please follow it.
 -  **Create your first page**
    Create a html file using your editor called `index.html`, and open it in your browser.
     -  Add a word as content to the file

        ```html
        apple
        ```

     -  Open it in the browser
     -  Add a second word separated by space

        ```html
        apple pear
        ```

     -  The browser only refreshes if you manually hit refresh because of the request mechanism
     -  Tell them to put the second word to a new line (not going to work because how whitespace characters are handled in html)

        ```html
        apple
        pear
        ```

     -  Show them that none of the whitespace characters are doing any change.

        ```html
        apple

        
           pear
        ```

     -  Show them this slide:
        [html document slide](https://docs.google.com/presentation/d/1xzn3PqVKyysVTnL48t3FmDc9-NapYVzMBxz5c_HR_5o/edit#slide=id.ge7c2a704f_0_0), 
        and explain what is an html document
     -  Show them this slide:
        [element nesting](https://docs.google.com/presentation/d/1xzn3PqVKyysVTnL48t3FmDc9-NapYVzMBxz5c_HR_5o/edit#slide=id.ge7c2a704f_0_26),
        and explain how to nest html elements
     -  Wrap the first word in an `<h1>` tag

        ```html
        <h1>apple</h1>
        pear
        ```

     -  Point out how the editor uses different colors, and how it helps to visually spot errors
        (for example not matched greater than characters)
     -  Explain that we use the html elements for sematical use rather than how it looks in the browser.
        Good examples: Google crawler, screen readers
     -  Add a comment to the file and check it in the browser
     -  Tell the purpose of comments (not describing the code rather explaining)
     -  Show them how to write a tag as content using `&gt;` `&lt;` 
     -  Show them the `&amp;`
     -  Explain them to only use these
 -  **Start with the content.**
    Copy-paste the headingsa and the first 3 paragraphs of text from [the article above](https://medium.com/galleys/how-she-got-there-3a64d89ba112#.8eknq2olp) to start with.
     -  Paste the content to the file like this:
        ```html
        How She Got There
        An interview with Mule Design’s Erika Hall about philosophy, phone calls and her professional journey.

        In the fall of 2013 I interviewed Erika Hall, co-founder of Mule Design Studio, one of the most influential design practices in North America. It was the first of fourteen interviews that I would conduct for my book How They Got There: Interviews With Digital Designers About Their Careers, and so in many ways it was the most important, too.
        Erika had been profiled numerous times in many different forums, and her insights on design, business and technology were well known. I was after something narrower, though. I wanted to hear about the nitty gritty of her professional journey, the trials and tribulations she encountered in finding meaningful work, and the stories of her lucky breaks and less lucky mishaps. The goal of How They Got There was to document the random things that conspire together to forge every career, even very high profile ones like Erika’s.
        I knew that, if it went off well, our discussion would serve as a kind of template for the others that would follow, and so I was relieved when Erika talked about her professional life with such unaffected candor and incisive wit. Her tales of the first dot-com bubble and burst, and how she salvaged from that wreckage the building blocks that would lead to Mule Design, were exactly what I was looking for. This interview remains one of my very favorites from all of the ones I conducted for How They Got There.
        ```
     -  Show the toggle soft wrap feature in atom
 -  **Give it some structure.**
    What semantic role do these paragraphs fill? Divide it into a few separate HTML tags.
     -  Ask them to point out different semantic elements on the article
         - iamge
         - headings
         - links
         - paragraphs
         - the paragraphs are emphesized
     -  Wrap the titles to heading tags

        ```html
        <h1>How She Got There<h1>
        <h2>
          An interview with Mule Design’s Erika Hall about philosophy, phone calls and her professional journey.
        <h2>

        In the fall of 2013 I interviewed Erika Hall, co-founder of Mule Design Studio, one of the most influential design practices in North America. It was the first of fourteen interviews that I would conduct for my book How They Got There: Interviews With Digital Designers About Their Careers, and so in many ways it was the most important, too.
        Erika had been profiled numerous times in many different forums, and her insights on design, business and technology were well known. I was after something narrower, though. I wanted to hear about the nitty gritty of her professional journey, the trials and tribulations she encountered in finding meaningful work, and the stories of her lucky breaks and less lucky mishaps. The goal of How They Got There was to document the random things that conspire together to forge every career, even very high profile ones like Erika’s.
        I knew that, if it went off well, our discussion would serve as a kind of template for the others that would follow, and so I was relieved when Erika talked about her professional life with such unaffected candor and incisive wit. Her tales of the first dot-com bubble and burst, and how she salvaged from that wreckage the building blocks that would lead to Mule Design, were exactly what I was looking for. This interview remains one of my very favorites from all of the ones I conducted for How They Got There.
        ```

     -  Explain how the `<h1>` and `<h2>` is indented and the importance of indentation
     -  Add the paragraphs, links, and `<em>`-s

        ```html
        <h1>How She Got There</h1>
        <h2>
          An interview with Mule Design’s Erika Hall about philosophy, phone calls and her professional journey.
        </h2>
        <p>
          <em>
            In the fall of 2013 I interviewed Erika Hall, co-founder of
            <a href="http://muledesign.com/" target="_blank">Mule Design Studio</a>, one of the most influential design practices in North America. It was the first of fourteen interviews that I would conduct for my book <a href="http://howtheygotthere.com/" target="_blank">How They Got There: Interviews With Digital Designers About Their Careers</a>, and so in many ways it was the most important, too.
          </em>
        </p>
        <p>
          <em>
            Erika had been profiled numerous times in many different forums, and her insights on design, business and technology were well known. I was after something narrower, though. I wanted to hear about the nitty gritty of her professional journey, the trials and tribulations she encountered in finding meaningful work, and the stories of her lucky breaks and less lucky mishaps. The goal of How <a href="http://howtheygotthere.com/" target="_blank">They Got There</a> was to document the random things that conspire together to forge every career, even very high profile ones like Erika’s.
          </em>
        </p>
        <p>
          <em>
            I knew that, if it went off well, our discussion would serve as a kind of template for the others that would follow, and so I was relieved when Erika talked about her professional life with such unaffected candor and incisive wit. Her tales of the first dot-com bubble and burst, and how she salvaged from that wreckage the building blocks that would lead to Mule Design, were exactly what I was looking for. This interview remains one of my very favorites from all of the ones I conducted for How They Got There.
          </em>
        </p>
        ```

     -  Explain the difference between `<em>` and `<i>`
 -  **Add a header image.**
    Download the image from the medium site, and save it next to your html file.
     -  Tell them to rename the image
     -  Show them the broken image link
     -  add the image tag and wrap the artice to an `<article>` tag

        ```html
        <img src="road.jpg" alt="Road">
        <article>
          <h1>How She Got There</h1>
          <h2>
            An interview with Mule Design’s Erika Hall about philosophy, phone calls and her professional journey.
          </h2>
          <p>
            <em>
              In the fall of 2013 I interviewed Erika Hall, co-founder of
              <a href="http://muledesign.com/" target="_blank">Mule Design Studio</a>, one of the most influential design practices in North America. It was the first of fourteen interviews that I would conduct for my book <a href="http://howtheygotthere.com/" target="_blank">How They Got There: Interviews With Digital Designers About Their Careers</a>, and so in many ways it was the most important, too.
            </em>
          </p>
          <p>
            <em>
              Erika had been profiled numerous times in many different forums, and her insights on design, business and technology were well known. I was after something narrower, though. I wanted to hear about the nitty gritty of her professional journey, the trials and tribulations she encountered in finding meaningful work, and the stories of her lucky breaks and less lucky mishaps. The goal of How <a href="http://howtheygotthere.com/" target="_blank">They Got There</a> was to document the random things that conspire together to forge every career, even very high profile ones like Erika’s.
            </em>
          </p>
          <p>
            <em>
              I knew that, if it went off well, our discussion would serve as a kind of template for the others that would follow, and so I was relieved when Erika talked about her professional life with such unaffected candor and incisive wit. Her tales of the first dot-com bubble and burst, and how she salvaged from that wreckage the building blocks that would lead to Mule Design, were exactly what I was looking for. This interview remains one of my very favorites from all of the ones I conducted for How They Got There.
            </em>
          </p>
        </article>
        ```

     -  Explain the purpose of the `<article>` tag
 -  **Add in style.**
    Create a style.css file and link it to your HTML.
    How do you center content on the page?
    Try adding a custom font via [Google Fonts](https://www.google.com/fonts#UsePlace:use/Collection:Lato|Merriweather).
     -  Show them the basic html boilerplate and explain it's purpose

        ```html
        <!doctype html>
        <html lang="en">
          <head></head>
          <body>
            <img src="road.jpg" alt="Road">
            <article>
              <h1>How She Got There</h1>
              <h2>
                An interview with Mule Design’s Erika Hall about philosophy, phone calls and her professional journey.
              </h2>
              <p>
                <em>
                  In the fall of 2013 I interviewed Erika Hall, co-founder of
                  <a href="http://muledesign.com/" target="_blank">Mule Design Studio</a>, one of the most influential design practices in North America. It was the first of fourteen interviews that I would conduct for my book <a href="http://howtheygotthere.com/" target="_blank">How They Got There: Interviews With Digital Designers About Their Careers</a>, and so in many ways it was the most important, too.
                </em>
              </p>
              <p>
                <em>
                  Erika had been profiled numerous times in many different forums, and her insights on design, business and technology were well known. I was after something narrower, though. I wanted to hear about the nitty gritty of her professional journey, the trials and tribulations she encountered in finding meaningful work, and the stories of her lucky breaks and less lucky mishaps. The goal of How <a href="http://howtheygotthere.com/" target="_blank">They Got There</a> was to document the random things that conspire together to forge every career, even very high profile ones like Erika’s.
                </em>
              </p>
              <p>
                <em>
                  I knew that, if it went off well, our discussion would serve as a kind of template for the others that would follow, and so I was relieved when Erika talked about her professional life with such unaffected candor and incisive wit. Her tales of the first dot-com bubble and burst, and how she salvaged from that wreckage the building blocks that would lead to Mule Design, were exactly what I was looking for. This interview remains one of my very favorites from all of the ones I conducted for How They Got There.
                </em>
              </p>
            </article>
          </body>
        </html>
        ```

     -  Add the title, the charset meta tag, and link the stylesheet. Explain the purpose for each. (show them how the text changes on the browser tab)

        ```html
        <!doctype html>
        <html lang="en">
          <head>
            <title>How She Got There</title>
            <meta charset="utf-8">
            <link rel="stylesheet" href="style.css">
          </head>
          <body>
            <img src="road.jpg" alt="Road">
            <article>
              <h1>How She Got There</h1>
              <h2>
                An interview with Mule Design’s Erika Hall about philosophy, phone calls and her professional journey.
              </h2>
              <p>
                <em>
                  In the fall of 2013 I interviewed Erika Hall, co-founder of
                  <a href="http://muledesign.com/" target="_blank">Mule Design Studio</a>, one of the most influential design practices in North America. It was the first of fourteen interviews that I would conduct for my book <a href="http://howtheygotthere.com/" target="_blank">How They Got There: Interviews With Digital Designers About Their Careers</a>, and so in many ways it was the most important, too.
                </em>
              </p>
              <p>
                <em>
                  Erika had been profiled numerous times in many different forums, and her insights on design, business and technology were well known. I was after something narrower, though. I wanted to hear about the nitty gritty of her professional journey, the trials and tribulations she encountered in finding meaningful work, and the stories of her lucky breaks and less lucky mishaps. The goal of How <a href="http://howtheygotthere.com/" target="_blank">They Got There</a> was to document the random things that conspire together to forge every career, even very high profile ones like Erika’s.
                </em>
              </p>
              <p>
                <em>
                  I knew that, if it went off well, our discussion would serve as a kind of template for the others that would follow, and so I was relieved when Erika talked about her professional life with such unaffected candor and incisive wit. Her tales of the first dot-com bubble and burst, and how she salvaged from that wreckage the building blocks that would lead to Mule Design, were exactly what I was looking for. This interview remains one of my very favorites from all of the ones I conducted for How They Got There.
                </em>
              </p>
            </article>
          </body>
        </html>
        ```

     -  Show them this slide:
        [CSS syntax](https://docs.google.com/presentation/d/1xzn3PqVKyysVTnL48t3FmDc9-NapYVzMBxz5c_HR_5o/edit#slide=id.ge7c2a704f_0_30),
     -  Make everything red

        ```css
        body {
          color: red;
        }
        ```

     -  Show them how to create a comment in css
     -  Show them the wiew page source
     -  Show them the devloper tools
     -  Rewrite the html content using the devtools
     -  Inspect the body element
     -  Rewtire the css
     -  Ask for the simple differences, and show them one by one how to change it
         -  image margin

            ```css
            body {
              margin: 0;
            } 
            ```

         -  image size

            ```css
            img {
              width: 100%;
            }
            ```

         -  Center the content

            ```css
            article {
              max-width: 740px;
              margin-left: auto;
              margin-right: auto;
            }
            ```

         -  heading positions

            ```css
            h1 {
              text-align: center;
            }

            h2 {
              text-align: center;
            }
            ```

         -  Explain the problem with code duplication and refactor

            ```css
            h1,
            h2 {
              text-align: center;
            }
            ```

         -  Font sizes, colors and margins 

            ```css
            body {
              margin: 0;
              color: rgba(0, 0, 0, 0.8);
            }

            img {
              width: 100%;
            }

            article {
              max-width: 740px;
              margin-left: auto;
              margin-right: auto;
            }

            h1,
            h2 {
              text-align: center;
            }

            h1 {
              font-size: 40px;
              margin-top: 80px;
              margin-bottom: 5px;
            }

            h2 {
              color: rgba(0, 0, 0, 0.44);
              font-size: 27px;
              margin-top: 0;
              margin-bottom: 22px;
              font-weight: normal;
            }

            p {
              font-size: 21px;
              margin-bottom: 29px;
              margin-top: 0;
              line-height: 1.5;
            }

            a {
              font-weight: bold;
              color: rgba(0, 0, 0, 0.8);
            }
            ```

         -  Pick the fonts from google font and link it to the html, than add it to our css

            ```css
            body {
              margin: 0;
              color: rgba(0, 0, 0, 0.8);
              font-family: 'Merriweather', serif;
            }

            img {
              width: 100%;
            }

            article {
              max-width: 740px;
              margin-left: auto;
              margin-right: auto;
            }

            h1,
            h2 {
              font-family: 'Lato', sans-serif;
              text-align: center;
            }

            h1 {
              font-size: 40px;
              margin-top: 80px;
              margin-bottom: 5px;
            }

            h2 {
              color: rgba(0, 0, 0, 0.44);
              font-size: 27px;
              margin-top: 0;
              margin-bottom: 22px;
              font-weight: normal;
            }

            p {
              font-size: 21px;
              margin-bottom: 29px;
              margin-top: 0;
              line-height: 1.5;
            }

            a {
              font-weight: bold;
              color: rgba(0, 0, 0, 0.8);
            }
            ```


# What is this? This is a small blog app. Basically a static site generator.
It uses cpp to create html files from md.
It also allows for some configuration with `.toml` files.

# How do I use this?
Pretty simple. You just write blog entries into `/posts`.
Then you run the compiled binary in `/src`.
Voila. All the html and css is ready for deployment inside of `/out` directory.

# How do I compile the binary?
Simple. Just run `make` command and the magic will happen.

# How do I configure this?
There are `.toml` files inside of `/config` directory.
Every entry is pretty self-explanatory.

# How does the directory structure works?
Also pretty simple. You have:
- `/config` for config files
- `/examples` example of configuration files. Tests are dependent on it so don't edit the content of these files! You can copy it to `/config` and edit it there.
- `/out` for ready site. This folder should be on the web server.
- `/posts` here you write your blog posts. Every file should be in markdown format.
- `/src` for cpp files. Here's where you run the binary to translate your markdown posts into html.
- `/style` for css styling. You can tune it for your liking.
- `/templates` for html templates. The format is pretty simple, so you can edit it, if you like.

# Why did you do this?
Because I wanted a small utility for my personal blog that doesn't have any
javascript bullshit and is small, but also easy to write blog entries.
Besides it's a pretty cool project, If I do say so myself.

# Dependencies
- `Catch2` framework for unit tests
- `toml++` for toml parsing

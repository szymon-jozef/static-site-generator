# IMPORTANT
This is still work in progress. It doesn't work yet.
I pushed it onto github just to have easy access from other computers.
(I'm too lazy to make a private repo)

# What works, what doesn't?
As this is still a WIP, here is a short list of what works and what still needs work.
- [x] config parsing
- [x] metadata parsing
- [x] basic tests
- [x] parsing markdown
- [ ] generating html documents
- [ ] some nicer css styles
- [ ] more sensible templates
- [x] change yaml style metadata to toml

# What is this? 
This is a small blog app. Basically a static site generator.

# How does it work?
It creates html files from markdown files, then it inserts them into html templates.

# How do I use it?
It is very simple.
## First you need to compile the program
In `/src` directory.
`make`
## Then you write some blog posts
Every blog post needs to be in a different file in `/posts` directory.

*Don't forget to put metadata in the header*

An example from `/examples/post.md`
```md
---
[metadata]
author = "joseph"
date = 2026-01-01
title = "Example of a blog post"
tags = ["blog", "test", "lalilulelo"]
---
# This is an example post

In this example we will do a couple of cool markdown things.

## This is a h2 header
*This text is written in italic!*
### Look at this!
**This text is BOLD!**

## Hello world!

## Time to link some random website!
This [should be clickable](https://example.com)

## Image test
![this should show an image](image.png)

## This is an ordered list
1. one
2. six
3. seven

## This is an unordered one
- six
- nine
- six
- nine
```
## You also mustn't forget about creating a config file
In root repo directory.
`cp examples/config.toml config/`
Then you can edit it for your liking.

## Then you just run the binary
In `/src` directory.
`./blog`

## Finally! Your beautiful site will be in `/out` directory
From there you can rsync/push it to your server or do whatever you want to do with it.

# How does the directory structure work?
Also pretty simple. You have:
- `/config` for config files. Initially empty so you need to copy it from example dir or make one yourself.
- `/examples` example of configuration files. You can copy it to `/config` and edit it there.
- `/out` for processed site.
- `/posts` here you write your blog posts. Every file should be in markdown format, metadata included!.
- `/src` for cpp files. Here's where you run the binary to translate your markdown posts into html.
- `/style` for css styling. You can tune it for your liking.
- `/templates` for html templates. The format is pretty simple, so you can edit it, if you like.

# Config file explanation
## Fields
`[general]` - General info about your site. Mostly `<head>` info.
- lang – Language of the blog
- title – Html title of the MAIN site. It will only show in the index.

`[contact]` - Contact information in the footer.
- author – Your name/nickname/whatever
- email – Your email address | optional
- signal – Signal profile url | optional

Optional means it can be an empty string! Don't remove it from the file.

## Example
From `examples/config.toml`
```
[general]
lang = "en"
title = "Blog"

[contact]
author = "author"
email = "email@example.com"
signal = "signal url"
```

# Metadata explanation
Metadata is everything at the beginning of the markdown file between `---`.
It's also written in toml. Why toml? I already use it's parser so it's easy to implement.
Besides it's readable and easy to write.

## Fields
- author – the author of particular blog entry | string
- date – date of writing an entry | date
- title – title of blog entry | string
- tags – tags for blog entry. | array

## Example
```
[metadata]
author = "joseph"
date = 2026-01-01
title = "Example of a blog post"
tags = ["blog", "test", "lalilulelo"]
```

# Why did you do this?
Because I wanted to build something! It's a fun exercise.
Besides it's cool to host a blog with your own software.

# Dependencies
- `Catch2` framework for unit tests
- `toml++` for toml parsing
- `md4c` for markdown parsing

# IMPORTANT NOTICE
The project is developed for Linux only and is not expected to work on other platforms.

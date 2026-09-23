# Codebook

forked from [Github Repo](https://github.com/Jinkela-Xiao-Zuan-Feng-Mountaineer/Codebook.git)

## Setup

Enter the folder:

```
cd Codebook
```

Start Docker, then do the following.

First, build the Docker image:

```bash
docker build -t latex-build .
```

To build the codebook, run the command below (after any later change, this is the only command you need to run again):

```bash
docker run --rm -v ${PWD}:/usr/src/app latex-build
```

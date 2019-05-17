# pywal restore colorscheme

Pywal is a tool that generates color palettes from dominant colors in images, then applies the colors system-wide and on-the-fly in all of your favourite programs. Refer to [https://github.com/dylanaraps/pywal](https://github.com/dylanaraps/pywal).

The updated color scheme is only applied to running terminals, however, so if you want new terminals to also have the same look and feel then you need to run this when the shell starts up:
```bash
(cat ~/.cache/wal/sequences &)
```

So you might end up adding this to your `~/.bashrc` file. The problem with this is that if you ssh into your machine from another box then that will get the color scheme applied as well. Also unless you have something that stops the loading of the .bashrc file when you have a non-interactive shell then you may run into issues using scp for example.

This is a small bash/zsh snippet that restores the wal color scheme if:

   * a cached color scheme exists and
   * we are in an interactive shell and
   * we are not in a login shell

The reasoning for the latter is that typically a terminal opened in a desktop environment will not be using a login shell, whereas ssh will.

## How to install

Either download/clone this repository and add the following to your `~/.bashrc` file:
```bash
source path/to/wal_restore.inc
```

or alternatively just copy-paste the content directly into your `~/.bashrc` file.

NB: Sourcing is recommended if you end up picking up more than one of these bookmarklets as it avoids clutter.

It is also worth noting that you can reset the color scheme of a terminal using `tput init` (in case something is unreadable).

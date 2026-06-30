# Procsnap
Procsnap is a project that follows the suckless philosophy.

## What is procsnap exactly?
Procsnap is a lightweight Linux process profiler.

# Installation
## Clone the repo
```bash
git clone https://github.com/DankDown10256/procsnap
cd procsnap/
```
## Install
Execute the command below in the procsnap directory.
```bash
make
```
## Launch
Once the previous step is complete, you can launch the tool.
```bash
./procsnap <pid>          (see basic infos for a given PID)
./procsnap --json <pid>   (same as previous command but with JSON output)
./procsnap --diff <pid>   (see diff in VmRSS, VmSize or State of a given PID with a 1 sec interval)
./procsnap -g <name>      (in dev)
```

# Contributions/Feedback
I will be happy if you want to open issues, give feedback, or even contribute.

## Contributions
If you want to contribute to this project, you can follow the instructions here: [CONTRIBUTE.md](CONTRIBUTE.md).

# Thanks
Hope you will enjoy this project.

## License
procsnap is licensed under the GNU General Public License v2.0 (or later). See [LICENSE](LICENSE) for details.

# Contributing to procsnap

procsnap follows a workflow inspired by the Linux kernel: contributions are
submitted as patches by email, not as GitHub pull requests.

## How to submit a patch

1. Make your changes locally and commit them with `git commit`.
2. Generate your patch:
```bash
   git format-patch -1 HEAD
```
3. Send the patch by email to: **lucasp.linux@gmail.com**

   You can use `git send-email` directly:
```bash
   git send-email --to=lucasp.linux@gmail.com 0001-your-patch.patch
```

## Sign-off requirement

Every patch **must** include a `Signed-off-by` line with your real name,
certifying that you wrote it or have the right to submit it:

Signed-off-by: First Last your-email@example.com

Add it automatically with:
```bash
git commit -s
```

## Review process

After review, you will receive an email either way:
- **Accepted** — your patch will be applied, and you'll be notified.
- **Rejected** — you'll be notified with the reason, so you can revise and
  resubmit if relevant.

## Code style

- Keep changes minimal and focused (one logical change per patch).
- Match the existing code style (see `proc.c`/`main.c`).
- No unnecessary dependencies — procsnap stays suckless.

Thanks for contributing!

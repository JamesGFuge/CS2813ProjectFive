# Project 5

## Run Instructions

1. Open a terminal in `CS2813/Projects/Project5`.
2. Compile the program if needed:

```powershell
cl.exe /EHsc /nologo Project5.cpp
```

3. Run the compiled executable and provide `k` when prompted:

```powershell
.\Project5.exe
```

Then enter the value of `k`, for example `5`.

## Output for k = 5

```
Enter the value of k: Total Strings = 243
No Consecutive Same = 48
Probability = 0.1975
Strings with "CC" = 79
```

## Notes

Total strings were counted as `3^k` because each position can be `A`, `B`, or `C`. The "no consecutive same" count was computed by choosing 3 options for the first character and then 2 options for each subsequent position. The probability was calculated as the ratio of valid no-consecutive-same strings to the total number of strings. For the "CC" count, complement counting was used: the number of strings containing at least one `CC` equals total strings minus the number of strings that avoid `CC` entirely.

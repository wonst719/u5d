int F_FLAMES_000e(void);

// NOTE: just burning up some cpu cycles

// NOT MATCHING
int F_FLAMES_0000(void)
{
    // PUSH DS
    F_FLAMES_000e();
    // POP DS
}

// NOT MATCHING
int F_FLAMES_000e(void)
{
    // POP AX
    // PUSH AX
    // RET
    return 0;
}

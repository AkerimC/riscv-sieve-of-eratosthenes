.section .text
.global find_prime


find_prime:
    li t0, 2              # p = 2

outer_loop:
    // if (p*p > n) break
    mul t1, t0, t0        # t1 = p*p
    bgt t1, a1, done

    // if sieve[p] == 0, skip
    add t2, a0, t0        # &sieve[p]
    lbu t3, 0(t2)
    beqz t3, next_p

    # i = p*p
    mv t4, t1

inner_loop:
    # sieve[i] = 0
    add t5, a0, t4
    sb zero, 0(t5)

    # i += p
    add t4, t4, t0
    ble t4, a1, inner_loop

next_p:
    addi t0, t0, 1        # p++
    j outer_loop

done:
    ret

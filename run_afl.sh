cat /src/cgc_list | while read line; do
/AFLplusplus/afl-showmap  -i ../build_symsan/${line}_outseeds/ -o ${line}_symsan_trace -t 2000+  -- ./challenges/$line/$line
done

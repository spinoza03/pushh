while true; do
    n=$(seq 500 | sort -R | tr '\n' ' ')
    res=$(./push_swap $n | wc -l)
    if [ $res -gt 5500 ]; then
        echo $n
        break	
    fi
done

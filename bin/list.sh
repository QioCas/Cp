cd ~/Cp/Code/
set -e

for((y = 2021; y <= 2023; ++y)); do 
    cd $y
    for((m = 1; m <= 12; ++m)) do 
        FYM=~/Cp/Code/$y/$m/
        if [ -d "$FYM" ]; then 
            cd $m
            for((d = 1;d <= 59; ++d)) do
                FYMD=~/Cp/Code/$y/$m/$d/
                if [ -d "$FYMD" ]; then
                    cd $d
                    echo $y/$m/$d
                    echo -ne '\033[32m' 
                    ls
                    echo -ne '\033[0m'
                    cd ..
                fi
            done
            cd ..
        fi
    done
    cd ..
done
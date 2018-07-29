[ "${2}" == "" ] || make all
folder="testcase"
testcase_path=$folder/${1}

cmd=./generator" "$testcase_path/${1}.tau2018" "$testcase_path/${1}.testcase
echo $cmd
$cmd

#nombre = Read-Host
#if ($nombre -eq ""){
#    Write-Error -Message "return code 100"
#}else{
#    echo "Hola $nombre"
#}
$number = Read-Host
if($number -lt 0 -Or $number -eq 0){
     Write-Error -Message "Invalid input $number"
}else{
    echo "Good one $number"
}

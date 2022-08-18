$nombre = Read-Host

if ($nombre -eq ""){
    Write-Error -Message "return code 100"
}else{
    echo "Hola $nombre"
}
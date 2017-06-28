<?php

$pem_certificate = "certificate.pem";
$pem_passphrase = "12345";

$series_name = file_get_contents('php://stdin');

$url = 'https://iot.lisha.ufsc.br/api/get.php';

$options = array(
    'http' => array(
        'header' => array(
            "Content-type: application/octet-stream",
            "Content-length: " . strlen($series_name)
        ),
        'method' => 'POST',
        'content' => $series_name
    ),
    'ssl' => array(
        'local_cert' => $pem_certificate,
        'passphrase' => $pem_passphrase,
        'verify_peer' => false,
    )
);

$context = stream_context_create($options);
$response = file_get_contents($url, false, $context);
$data = explode("[[", $response);
$data = explode("],[", $data[1]);
$data = str_replace("]]}]}]}", "", $data);
foreach($data as $item) {
    echo(explode(",", $item)[1]);
    echo("\n");
}
?>

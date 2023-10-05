<html>
<body>
<form action="rev.php" method="get">Enter the number:
<input type="number" name="num1" /> <br><br>
<input type="submit" name="submit" value="Find">
</form>

<?php

if(isset($_GET['submit']))
{

$num = $_GET['num1'];
$rev = 0;
$temp = $num;

for($i=1; $temp>1; $i++)
{
    $rem = $temp % 10;
    $rev = ($rev * 10) + $rem;
    $temp = $temp / 10; 
}
echo "The reverse of $num is $rev";
}
?>
</body>
</html>
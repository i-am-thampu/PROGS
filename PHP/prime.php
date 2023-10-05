<html>
    <body>
        <form action="prime.php" method="get">
            Enter first number:
            <input type="number" name="num" /> <br><br>
            <input type="submit" name="submit" value="Find"> />
        </form>
            
<?php

if(isset($_GET['submit']))
 {
     $num = $_GET['num'];
    
    $c=0;
    for($i=2;$i<$num;$i++)
    { 
        if($num%$i==0){$c++;break;
    }
    }
        if($c==0)
        {echo "$num is a prime number";}
    
    else
    echo"$num is not a prime number";
}
?>
    </body>
    </html>

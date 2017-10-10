
<!-- ex04-01 -->

<!DOCTYPE HTML>

<html>
<head>
		<title> </title>
    <meta http-equiv='Content-type' content='text/html; charset=utf-8'>
</head>
<body>
  <p style='color: #808000;'>이 문장은 인라인 스타일이 적용되었습니다.</p>
  <p>이 문장은 일반 문장입니다.</p>
</body>
</html>


<!-- ex04-02 -->

<!DOCTYPE HTML>

<html>
<head>
    <meta http-equiv='Content-type' content='text/html; charset=utf-8'>
		<title> </title>
		<style type="text/css">
		h1 {
			color: #808000;
			margin-left: 20px;
		}
		</style>
</head>
<body>
	<h1>내부 스타일 시트가 적용된 문장입니다.</h1>
  <h1>모든 h1에 적용됩니다.</h1>
</body>
</html>

<!-- ex04-03 -->
<!-- main.html -->

<!DOCTYPE HTML>

<html>
<head>
    <link rel="stylesheet" type="text/css"href="style.css" />
    <meta http-equiv='Content-type' content='text/html; charset=utf-8'>
		<title> </title>
</head>
<body>
	<h1>메인 페이지</h1>
  <h2>외부스타일:Hello!</h2>
</body>
</html>


<!-- sub.html -->

<!DOCTYPE HTML>

<html>
<head>
    <link rel="stylesheet" type="text/css"href="style.css" />
    <meta http-equiv='Content-type' content='text/html; charset=utf-8'>
		<title> </title>
</head>
<body>
	<h1>외부 스타일 시트가 적용된 문장입니다.</h1>
  <h2>서브 페이지입니다.</h2>
</body>
</html>

<!-- style.css -->

h1
{
  font-family:'맑은 고딕';
  font-size: 20px;
}

<!-- ex04-04 -->

<!DOCTYPE HTML>

<html>
<head>
    <meta http-equiv='Content-type' content='text/html; charset=utf-8'>
		<title> </title>
		<style type="text/css">
    p{
      color: maroon;
    }
		body{
			font-family: sans-serif;
		}
    </style>
</head>
<body>
	<h1>h1 tag Title</h1>
  <h2>h2 tag Title</h2>
  <p>p tag hello!</p>
  <p>p tag
    <em>hello!</em>
  </p>
</body>
</html>

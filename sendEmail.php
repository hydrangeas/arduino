<?php
	
	$name = trim($_POST['name']);
	$email = $_POST['email'];
	$subject = $_POST['subject'];
	$message = $_POST['message'];
	
	$site_owners_email = 'address@domain.com'; // Replace this with your own email address
	$site_owners_name = 'John Doe'; // replace with your name
	
	if ((strlen($name) < 2) || ($name == 'Your name')) {
		$error['name'] = "Please enter your name";	
	}
	
	
	if ((!preg_match('/^[a-z0-9&\'\.\-_\+]+@[a-z0-9\-]+\.([a-z0-9\-]+\.)*+[a-z]{2}/is', $email) || ($email) == 'Email')) {
		$error['email'] = "Please enter a valid email address";	
	}
	
	
	if ((strlen($subject) < 2) || ($subject) == 'Subject')  {
		$error['subject'] = "Please enter subject name";	
	}
	
	
	if ((strlen($message) < 3) || ($message) == 'Enter your message') {
		$error['message'] = "Please leave a message.";
	}	
	
	if (!$error) {
		
		require_once('phpMailer/class.phpmailer.php');
		$mail = new PHPMailer();
		
		$mail->From = $email;
		$mail->FromName = $name;
		$mail->Subject = $subject;
		$mail->AddAddress($site_owners_email, $site_owners_name);
//		$mail->AddAddress('address@domain.com', 'John Doe Jr.');
		$mail->Body = $message;
		
		$mail->Send();
		
		echo "<li class='success'> Congratulations, " . $name . ". We've received your email. We'll be in touch as soon as we possibly can! </li>";
		
	} # end if no error
	else {

		$response = (isset($error['name'])) ? "<li>" . $error['name'] . "</li> \n" : null;
		$response .= (isset($error['email'])) ? "<li>" . $error['email'] . "</li> \n" : null;
		$response .= (isset($error['subject'])) ? "<li>" . $error['subject'] . "</li> \n" : null;
		$response .= (isset($error['message'])) ? "<li>" . $error['message'] . "</li>" : null;
		
		echo $response;
	} # end if there was an error sending

?>
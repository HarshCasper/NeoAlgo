package des.exception;

/**
 * Validation Exception
 * 
 * 		class ValidationException is a public class which extends class Exception, this class acts as an custom
 * 		exception class which is raised when an error is found in any of the models which may include, different
 * 		expansion and compression models, plain text, original key, cipher text, some to name few.
 */
public class ValidationException extends Exception
{
	private static final long serialVersionUID = 2970348796624085019L;

	/**
	 * This is a public parameterize constructor of ValidationException class
	 *
	 * @param errorMessage This is the error message
	 */
	public ValidationException(String errorMessage)
	{
		super(errorMessage);
	}
}

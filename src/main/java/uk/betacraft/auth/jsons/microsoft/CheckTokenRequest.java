package uk.betacraft.auth.jsons.microsoft;

import javax.swing.JOptionPane;

import org.betacraft.launcher.Lang;

import com.google.gson.Gson;
import com.google.gson.JsonParseException;

import uk.betacraft.auth.MicrosoftAuth;
import uk.betacraft.auth.Request;
import uk.betacraft.auth.RequestUtil;
import uk.betacraft.util.WebData;

public class CheckTokenRequest extends Request {

	public CheckTokenRequest(String devcode, String refreshtoken) {
		REQUEST_URL = "https://login.microsoftonline.com/consumers/oauth2/v2.0/token";
		PROPERTIES.put("Content-Type", "application/x-www-form-urlencoded");

		if (devcode != null) {
			POST_DATA = "client_id=" + MicrosoftAuth.CLIENT_ID +
					"&grant_type=urn:ietf:params:oauth:grant-type:device_code" +
					"&device_code=" + devcode;
		} else if (refreshtoken != null) {
			POST_DATA = "client_id=" + MicrosoftAuth.CLIENT_ID +
					"&grant_type=refresh_token" +
					"&refresh_token=" + refreshtoken;
		}
		type = RequestType.POST;
	}

	@Override
	public CheckTokenResponse perform() {
		Gson gson = new Gson();
		String response = MicrosoftAuth.fireAuthRequest(this);

		CheckTokenResponse ret;
		try {
			ret = gson.fromJson(response, CheckTokenResponse.class);
		} catch (JsonParseException ex) {
			return null;
		}
		return ret;
	}
}

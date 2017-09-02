package com.greenfox.aze.p2pchat;

import retrofit2.Call;
import retrofit2.http.Body;
import retrofit2.http.GET;
import retrofit2.http.POST;

/**
 * Created by aze on 22/05/17.
 */

public interface ApiService {
    @GET("/api/messages")
    Call<MessageResponse> getMessages();

    @POST("/api/messages")
    Call<StatusResponse> postMessage(@Body Message message);
}
